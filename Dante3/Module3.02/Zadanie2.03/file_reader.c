#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <errno.h>
#include "file_reader.h"

struct clusters_chain_t* get_chain_fat16(const uint8_t* fat_buffer, size_t fat_size, uint16_t first_cluster)
{
    if (!fat_buffer || fat_size < 2 || first_cluster < 2)
    {
        return NULL;
    }

    struct clusters_chain_t* chain = malloc(sizeof(*chain));
    if (!chain)
    {
        return NULL;
    }

    chain->clusters = NULL;
    chain->size = 0;

    uint16_t current = first_cluster;

    while (1)
    {
        uint16_t *temp = realloc(chain->clusters, sizeof(uint16_t) * (chain->size + 1));
        if (!temp)
        {
            free(chain->clusters);
            free(chain);
            return NULL;
        }
        chain->clusters = temp;
        chain->clusters[chain->size] = current;
        chain->size++;

        uint16_t next = *(const uint16_t*)(fat_buffer + current * 2);

        if (next >= 0xFFF8)
        {
            break;
        }
        if (next < 2)
        {
            break;
        }

        current = next;
    }

    return chain;
}

struct disk_t *disk_open_from_file(const char *volume_file_name)
{
    if (volume_file_name == NULL)
    {
        errno = EFAULT;
        return NULL;
    }

    struct disk_t *value_to_return = malloc(sizeof(struct disk_t));
    if (value_to_return == NULL)
    {
        // Brak pamięci:
        errno = ENOMEM;
        return NULL;
    }

    value_to_return->file = fopen(volume_file_name, "rb");
    if (value_to_return->file == NULL)
    {
        free(value_to_return);
        errno = ENOENT;
        return NULL;
    }

    return value_to_return;
}

int disk_close(struct disk_t *pdisk)
{
    if (pdisk == NULL)
    {
        errno = EFAULT;
        return -1;
    }
    if (pdisk->file != NULL)
    {
        fclose(pdisk->file);
    }
    free(pdisk);
    return 0;
}

int disk_read(struct disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read)
{
    if (pdisk == NULL || pdisk->file == NULL || buffer == NULL)
    {
        errno = EFAULT;
        return -1;
    }
    if (first_sector < 0 || sectors_to_read < 1)
    {
        errno = ERANGE;
        return -1;
    }

    if (fseek(pdisk->file, (long)first_sector * 512, SEEK_SET) != 0)
    {
        errno = ERANGE;
        return -1;
    }

    size_t read_count = fread(buffer, 512, (size_t)sectors_to_read, pdisk->file);
    if (read_count != (size_t)sectors_to_read)
    {
        errno = ERANGE;
        return -1;
    }

    return 0;
}

struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector)
{
    if (pdisk == NULL || pdisk->file == NULL)
    {
        errno = EFAULT;
        return NULL;
    }

    struct fat_super_t *variable_to_fill = malloc(sizeof(struct fat_super_t));
    if (variable_to_fill == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    if (0 != disk_read(pdisk, (int32_t) first_sector, variable_to_fill, 1))
    {
        free(variable_to_fill);
        errno = EINVAL;
        return NULL;
    }

    if (variable_to_fill->magic != 0xAA55)
    {
        free(variable_to_fill);
        errno = EINVAL;
        return NULL;
    }

    struct volume_t *variable_to_return = malloc(sizeof(struct volume_t));
    if (variable_to_return == NULL)
    {
        free(variable_to_fill);
        errno = ENOMEM;
        return NULL;
    }

    variable_to_return->pdisk = pdisk;
    variable_to_return->super = variable_to_fill;

    if (variable_to_fill->logical_sectors16 == 0)
        variable_to_return->volume_size = variable_to_fill->logical_sectors32;
    else
        variable_to_return->volume_size = variable_to_fill->logical_sectors16;

    int reserved_sectors = variable_to_fill->reserved_sectors;

    int fat_offset = reserved_sectors;
    int fat_size = variable_to_fill->sectors_per_fat;

    variable_to_return->fat = malloc(fat_size * variable_to_fill->bytes_per_sector);
    if (variable_to_return->fat == NULL)
    {
        free(variable_to_fill);
        free(variable_to_return);
        errno = ENOMEM;
        return NULL;
    }

    if (0 != disk_read(pdisk, fat_offset, variable_to_return->fat, fat_size))
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return);
        errno = EINVAL;
        return NULL;
    }

    void *some_variable_to_store = malloc(fat_size * variable_to_fill->bytes_per_sector);
    if (some_variable_to_store == NULL)
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return);
        errno = ENOMEM;
        return NULL;
    }

    if (0 != disk_read(pdisk, fat_offset + fat_size, some_variable_to_store, fat_size))
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return);
        free(some_variable_to_store);
        errno = EINVAL;
        return NULL;
    }

    if (memcmp(variable_to_return->fat, some_variable_to_store,
               fat_size * variable_to_fill->bytes_per_sector) != 0)
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return);
        free(some_variable_to_store);
        errno = EINVAL;
        return NULL;
    }
    free(some_variable_to_store);

    int root_dir_sectors = (int)((variable_to_fill->root_dir_capacity * sizeof(struct dir_entry_read_t))
                                 / variable_to_fill->bytes_per_sector);


    int our_start = fat_offset + 2 * fat_size;

    variable_to_return->root_dir = malloc(variable_to_fill->root_dir_capacity * sizeof(struct dir_entry_read_t));
    if (variable_to_return->root_dir == NULL)
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return);
        errno = ENOMEM;
        return NULL;
    }

    if (0 != disk_read(pdisk, our_start, variable_to_return->root_dir, root_dir_sectors))
    {
        free(variable_to_fill);
        free(variable_to_return->fat);
        free(variable_to_return->root_dir);
        free(variable_to_return);
        errno = EINVAL;
        return NULL;
    }

    variable_to_return->first_data_sector = our_start + root_dir_sectors;

    if (variable_to_fill->logical_sectors16 == 0)
        variable_to_return->usable_cluster_count = variable_to_fill->logical_sectors32 - variable_to_return->first_data_sector;
    else
        variable_to_return->usable_cluster_count = variable_to_fill->logical_sectors16 - variable_to_return->first_data_sector;

    return variable_to_return;
}

int fat_close(struct volume_t *pvolume)
{
    if (pvolume == NULL)
    {
        errno = EFAULT;
        return -1;
    }
    free(pvolume->fat);
    free(pvolume->root_dir);
    free(pvolume->super);
    free(pvolume);
    return 0;
}

struct file_t *file_open(struct volume_t *pvolume, const char *file_name)
{
    if (pvolume == NULL || pvolume->fat == NULL ||
        pvolume->root_dir == NULL || pvolume->super == NULL ||
        file_name == NULL)
    {
        errno = EFAULT;
        return NULL;
    }

    struct file_t *value_to_return = malloc(sizeof(struct file_t));
    if (value_to_return == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    struct dir_entry_read_t *enter_fat = pvolume->root_dir;
    int found = 0;

    for (int i = 0; i < pvolume->super->root_dir_capacity; i++)
    {
        struct dir_entry_t *temporary = read_directory_entry(enter_fat + i);
        if (temporary == NULL)
        {

            free(value_to_return);
            errno = ENOENT;
            return NULL;
        }

        if (strcmp(temporary->name, file_name) == 0)
        {
            if (temporary->is_directory == 1)
            {
                free(value_to_return);
                free(temporary);
                errno = EISDIR;
                return NULL;
            }
            value_to_return->file_info = *(enter_fat + i);
            value_to_return->fat = pvolume;

            int number_first = (enter_fat + i)->younger_two_bytes_first_cluster_number;

            value_to_return->fatChain = get_chain_fat16(
                pvolume->fat,
                pvolume->usable_cluster_count,
                (uint16_t)number_first
            );
            if (value_to_return->fatChain == NULL)
            {
                free(value_to_return);
                free(temporary);
                errno = ENOMEM;
                return NULL;
            }

            value_to_return->pos = 0;
            free(temporary);

            found = 1;
            break;
        }
        free(temporary);
    }

    if (!found)
    {
        free(value_to_return);
        errno = ENOENT;
        return NULL;
    }

    return value_to_return;
}

int file_close(struct file_t *stream)
{
    if (stream == NULL)
    {
        errno = EFAULT;
        return -1;
    }
    free(stream->fatChain->clusters);
    free(stream->fatChain);
    free(stream);
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream)
{
    if (!ptr || !stream || !stream->fatChain || !stream->fatChain->clusters)
    {
        errno = EFAULT;
        return (size_t)-1;
    }
    if (size == 0 || nmemb == 0)
    {
        return 0;
    }

    const size_t bytes_to_read_total = size * nmemb;

    size_t bytes_read = 0;

    const size_t cluster_size = 512UL * stream->fat->super->sectors_per_cluster;
    char *cluster_buffer = malloc(cluster_size);
    if (!cluster_buffer)
    {
        errno = ENOMEM;
        return (size_t)-1;
    }

    while (bytes_read < bytes_to_read_total)
    {
        if (stream->pos >= (int32_t)stream->file_info.size)
            break;

        size_t cluster_index = (size_t)stream->pos / cluster_size;
        if (cluster_index >= stream->fatChain->size)
        {
            break;
        }

        uint16_t cluster_num = stream->fatChain->clusters[cluster_index];

        size_t offset_in_cluster = (size_t)stream->pos % cluster_size;

        int sector_offset = (int)(stream->fat->first_data_sector
                                + (cluster_num - 2) * stream->fat->super->sectors_per_cluster);
        if (disk_read(stream->fat->pdisk, sector_offset, cluster_buffer,
                      stream->fat->super->sectors_per_cluster) != 0)
        {
            free(cluster_buffer);

            errno = ERANGE;
            return (size_t)-1;
        }

        size_t bytes_in_this_cluster = cluster_size - offset_in_cluster;

        size_t bytes_left_to_read = bytes_to_read_total - bytes_read;

        size_t file_remaining = (size_t)stream->file_info.size - (size_t)stream->pos;

        size_t copy_size = bytes_in_this_cluster;
        if (copy_size > bytes_left_to_read)
            copy_size = bytes_left_to_read;
        if (copy_size > file_remaining)
            copy_size = file_remaining;

        memcpy((char*)ptr + bytes_read,
               cluster_buffer + offset_in_cluster,
               copy_size);

        bytes_read += copy_size;
        stream->pos += (int32_t)copy_size;
    }

    free(cluster_buffer);


    size_t full_elems_read = bytes_read / size;
    return full_elems_read;
}


int32_t file_seek(struct file_t *stream, int32_t offset, int whence)
{
    if (stream == NULL || stream->fatChain == NULL || stream->fatChain->clusters == NULL)
    {
        errno = EFAULT;
        return -1;
    }

    switch (whence)
    {
        case SEEK_SET:
        {
            if (offset < 0 || offset > (int32_t)stream->file_info.size)
            {
                errno = ERANGE;
                return -1;
            }
            stream->pos = offset;
            return 0;
        }
        case SEEK_CUR:
        {
            int32_t newPos = stream->pos + offset;
            if (newPos < 0 || newPos > (int32_t)stream->file_info.size)
            {
                errno = ERANGE;
                return -1;
            }
            stream->pos = newPos;
            return 0;
        }
        case SEEK_END:
        {
            int32_t newPos = (int32_t)stream->file_info.size + offset;
            if (newPos < 0 || offset > 0)
            {
                errno = ERANGE;
                return -1;
            }
            stream->pos = newPos;
            return 0;
        }
        default:
            errno = EINVAL;
            return -1;
    }
}



struct dir_entry_t *read_directory_entry(struct dir_entry_read_t *stuff)
{
    if (!stuff) return NULL;

    struct dir_entry_t *returning_value = calloc(1, sizeof(struct dir_entry_t));
    if (!returning_value) return NULL;

    int i = 0;
    while (i < 8 && stuff->name[i] != ' ' && stuff->name[i] != '\0')
    {
        i++;
    }
    strncat(returning_value->name, stuff->name, i);

    int j = 0;
    while (j < 3 && stuff->extension[j] != ' ' && stuff->extension[j] != '\0')
    {
        j++;
    }
    if (j > 0)
    {
        strcat(returning_value->name, ".");
        strncat(returning_value->name, stuff->extension, j);
    }

    returning_value->is_archived  = (stuff->attribute & FAT_ATTRIB_ARCHIVE) ? 1 : 0;
    returning_value->is_directory = (stuff->attribute & FAT_DIRECTORY)      ? 1 : 0;
    returning_value->is_system    = (stuff->attribute & FAT_ATTRIB_SYSTEM)  ? 1 : 0;
    returning_value->is_hidden    = (stuff->attribute & FAT_ATTRIB_HIDDEN)  ? 1 : 0;
    returning_value->is_readonly  = (stuff->attribute & FAT_ATTRIB_READONLY)? 1 : 0;

    returning_value->size = stuff->size;

    union little_endian_t temp;
    temp.types[0] = stuff->creation_date[0];
    temp.types[1] = stuff->creation_date[1];
    returning_value->creation_date.year  = (uint16_t)((temp.sum >> 9) + 1980);
    returning_value->creation_date.month = (uint8_t)((temp.sum >> 5) & 0x0F);
    returning_value->creation_date.day   = (uint8_t)(temp.sum & 0x1F);

    temp.types[0] = stuff->creation_time[0];
    temp.types[1] = stuff->creation_time[1];
    returning_value->creation_time.hour    = (uint8_t)(temp.sum >> 11);
    returning_value->creation_time.minutes = (uint8_t)((temp.sum >> 5) & 0x3F);
    returning_value->creation_time.seconds = (uint8_t)((temp.sum & 0x1F) * 2);

    return returning_value;
}

struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path)
{
    if (pvolume == NULL || pvolume->fat == NULL || pvolume->root_dir == NULL
        || pvolume->super == NULL || dir_path == NULL)
    {
        errno = EFAULT;
        return NULL;
    }

    if (strcmp(dir_path, "\\") != 0)
    {
        errno = ENOENT;
        return NULL;
    }

    struct dir_t *returning_value = malloc(sizeof(struct dir_t));
    if (!returning_value)
    {
        errno = ENOMEM;
        return NULL;
    }

    returning_value->dir_position = 0;
    returning_value->dir_size = pvolume->super->root_dir_capacity;
    returning_value->dir_data = pvolume->root_dir;

    return returning_value;
}

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry)
{
    if (pdir == NULL || pentry == NULL)
    {
        errno = EFAULT;
        return -1;
    }

    while (pdir->dir_position < pdir->dir_size)
    {
        struct dir_entry_read_t *raw_entry =
            (struct dir_entry_read_t *)pdir->dir_data + pdir->dir_position;
        pdir->dir_position++;

        if (raw_entry->name[0] == '\0' || raw_entry->name[0] == (char)0xE5)
            continue;
        if (raw_entry->attribute & FAT_ATTRIB_VOLUME)
            continue;

        struct dir_entry_t *directory = read_directory_entry(raw_entry);
        if (!directory)
        {
            errno = EIO;
            return -1;
        }

        *pentry = *directory;
        free(directory);

        return 0;
    }

    return 1;
}

int dir_close(struct dir_t *pdir)
{
    if (pdir == NULL)
    {
        errno = EFAULT;
        return -1;
    }
    free(pdir);
    return 0;
}
