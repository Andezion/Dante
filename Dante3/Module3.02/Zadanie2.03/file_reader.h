#ifndef FAT12_FILE_READER_H
#define FAT12_FILE_READER_H

#include <stdint.h>
#include <stdio.h>

struct disk_t
{
    FILE *file;
};

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct fat_super_t
{
    uint8_t jumpCode[3];
    char oemName[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t  media_type;
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;
    uint16_t chs_sectors_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t media_id;
    uint8_t chs_head;
    uint8_t ext_bpb_signature;
    uint32_t serial_number;
    char volume_label[11];
    char fsid[8];
    uint8_t bootCode[448];
    uint16_t magic;
} __attribute__(( packed ));

struct volume_t
{
    struct disk_t *pdisk;
    struct fat_super_t *super;
    uint64_t volume_size;
    void* fat;
    void* root_dir;
    void *fat_chain_start;
    uint32_t first_data_sector;
    uint32_t usable_cluster_count;

} __attribute__ (( packed ));

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct creation_time_t
{
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
}__attribute__((packed));

struct creation_date_t
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
}__attribute__((packed));

union little_endian_t
{
    uint16_t sum;
    uint8_t types[2];
} __attribute__(( packed ));

enum fat_attribute_t
{
    FAT_ATTRIB_READONLY = 0x01,
    FAT_ATTRIB_HIDDEN = 0x02,
    FAT_ATTRIB_SYSTEM = 0x04,
    FAT_ATTRIB_VOLUME = 0x08,
    FAT_DIRECTORY = 0x10,
    FAT_ATTRIB_ARCHIVE = 0x20,
} __attribute__(( packed ));

struct dir_entry_read_t
{
    char name[8];
    char extension[3];

    uint8_t attribute;
    uint8_t reserved_for_windowsNT;

    uint8_t creation_time_in_tenths_of_sec;

    uint8_t creation_time[2];
    uint8_t creation_date[2];
    uint8_t last_access_date[2];

    uint16_t older_two_bytes_fist_cluster_number;

    uint8_t last_modification_time[2];
    uint8_t last_modification_date[2];

    uint16_t younger_two_bytes_first_cluster_number;
    uint32_t size;

} __attribute__((packed));

struct dir_entry_t *read_directory_entry(struct dir_entry_read_t *stuff);
struct clusters_chain_t *get_chain_fat12(const void *const buffer, size_t size, uint16_t first_cluster);

struct dir_entry_t
{
    char name[13];

    uint32_t size;

    uint8_t is_archived;
    uint8_t is_readonly;

    uint8_t is_system;
    uint8_t is_hidden;

    uint8_t is_directory;
    struct creation_time_t creation_time;
    struct creation_date_t creation_date;
};

struct clusters_chain_t
{
    uint16_t *clusters;
    size_t size;
};

struct file_t
{
    struct dir_entry_read_t file_info;
    struct clusters_chain_t *fatChain;
    int32_t pos;
    struct volume_t *fat;
};

struct file_t *file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);


struct dir_t
{
    void *dir_data;
    int dir_position;
    int dir_size;
};

struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path);
int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry);
int dir_close(struct dir_t *pdir);

struct clusters_chain_t* get_chain_fat16(const uint8_t* fat_buffer, size_t fat_size, uint16_t first_cluster);

#endif //FAT12_FILE_READER_H
