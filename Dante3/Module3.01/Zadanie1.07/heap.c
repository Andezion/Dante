#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "custom_unistd.h"
#include "heap.h"


#define FENCE_LENGTH 8
#define ALIGNMENT 4096

memory_manager_t memory_manager = {NULL, 0, NULL};
char fence_value[] = "1ECDC95B";

size_t calculateChunkSize(memory_chunk_t *chunk)
{
    size_t little_chunk;
    little_chunk = chunk->size;

    if (chunk->next != NULL)
    {
        little_chunk = (size_t) ((uint8_t *) chunk->next - (uint8_t *) chunk) - sizeof(memory_chunk_t) - 2 * FENCE_LENGTH;
    }

    return little_chunk;
} // ok

int heap_setup(void)
{
    void *temporary;
    temporary = custom_sbrk(0);

    if (temporary != (void *) -1)
    {
        memory_manager.first_memory_chunk = NULL;

        memory_manager.memory_size = 0;

        memory_manager.memory_start = temporary;

        return 0;
    }
    return -1;
} // ok

void heap_clean(void)
{
    if (memory_manager.memory_start != NULL && memory_manager.memory_size > 0)
    {
        custom_sbrk(-((long long) memory_manager.memory_size));

        memory_manager.first_memory_chunk = NULL;

        memory_manager.memory_start = NULL;

        memory_manager.memory_size = 0;

        return;
    }

    memory_manager.first_memory_chunk = NULL;

    memory_manager.memory_start = NULL;

    memory_manager.memory_size = 0;
} // ok
void *heap_malloc(size_t size)
{
    if (size != 0 && heap_validate() == 0)
    {
        memory_chunk_t *clean_chunk;
        clean_chunk = memory_manager.first_memory_chunk;

        memory_chunk_t *previous;
        previous = NULL;

        for (; clean_chunk != NULL;)
        {
            if (clean_chunk->size < size || clean_chunk->free != 1)
            {
                previous = clean_chunk;

                clean_chunk = clean_chunk->next;

                if (clean_chunk != NULL)
                {
                    clean_chunk->prev = previous;
                }
                continue;
            }
            break;
        }

        if (clean_chunk != NULL)
        {
            clean_chunk->free = 0;

            clean_chunk->size = size;

            uint8_t *pointer = (uint8_t *) clean_chunk;
            pointer = pointer + sizeof(memory_chunk_t);

            HELPER2(pointer, size)
            clean_chunk->checksum = calculate_checksum(clean_chunk);

            return pointer;
        }

        size_t block = sizeof(memory_chunk_t) + FENCE_LENGTH * 2 + size;

        memory_chunk_t *new_chunk = custom_sbrk((long) block);

        if (new_chunk != (void *) -1)
        {
            memory_manager.memory_size = memory_manager.memory_size + block;

            if (memory_manager.first_memory_chunk != NULL)
            {
                memory_chunk_t *chunk = memory_manager.first_memory_chunk;
                for (; chunk != NULL;)
                {
                    previous = chunk;

                    chunk = chunk->next;

                    if (chunk != NULL)
                    {
                        chunk->prev = previous;
                    }
                }

                chunk = new_chunk;

                chunk->next = NULL;

                chunk->prev = previous;

                chunk->free = 0;

                chunk->size = size;

                chunk->prev->next = chunk;

                chunk->prev->checksum = calculate_checksum(chunk->prev);

                uint8_t *pointer = (uint8_t *) chunk;

                pointer = pointer + sizeof(memory_chunk_t);

                HELPER2(pointer, size)

                chunk->checksum = calculate_checksum(chunk);

                return pointer;
            }

            memory_manager.first_memory_chunk = new_chunk;

            memory_chunk_t *to_fill = new_chunk;

            to_fill->next = NULL;

            to_fill->prev = NULL;

            to_fill->size = size;

            to_fill->free = 0;

            uint8_t *pointer = (uint8_t *) to_fill;

            pointer = pointer + sizeof(memory_chunk_t);

            HELPER2(pointer, size)

            to_fill->checksum = calculate_checksum(to_fill);

            return pointer;
        }
        return NULL;
    }
    return NULL;
} // ok
void *heap_calloc(size_t number, size_t size) // ok
{
    void *pointer;
    pointer = heap_malloc(number * size);

    if (pointer == NULL)
    {
        return NULL;
    }

    memset(pointer, 0, size * number);

    return pointer;
}
void *heap_realloc(void *memblock, size_t count)
{
    if (heap_validate() == 0)
    {
        if (count != 0)
        {
            if (get_pointer_type(memblock) == pointer_null)
            {
                void *helper_to_return;

                helper_to_return = heap_malloc(count);

                return helper_to_return;
            }

            if (get_pointer_type(memblock) != pointer_valid)
            {
                return NULL;
            }

            if (memory_manager.memory_start == NULL && memory_manager.memory_size == 0 && memory_manager.
                first_memory_chunk
                == NULL)
            {
                return NULL;
            }

            memory_chunk_t *working_on_that;

            working_on_that = (memory_chunk_t *) ((uint8_t *) memblock - sizeof(memory_chunk_t) - FENCE_LENGTH);

            if (working_on_that->size != count)
            {
                if (working_on_that->size <= count)
                {
                    size_t size = working_on_that->size;
                    if (working_on_that->next != NULL)
                    {
                        size = calculateChunkSize(working_on_that);
                    }

                    if (working_on_that->next != NULL)
                    {
                        if (working_on_that->next->free != 1 || working_on_that->next->size + sizeof(memory_chunk_t) +
                            FENCE_LENGTH * 2 < count - size)
                        {
                            void *temporary;

                            temporary = heap_malloc(count);

                            if (temporary == NULL)
                            {
                                return NULL;
                            }

                            memcpy(temporary, memblock, working_on_that->size);

                            heap_free(memblock);

                            return temporary;
                        }

                        heap_free(memblock);

                        return heap_malloc(count);
                    }

                    void *taker_value;

                    taker_value = custom_sbrk((count - working_on_that->size));

                    if (taker_value == (void *) -1)
                    {
                        return NULL;
                    }

                    memory_manager.memory_size = memory_manager.memory_size + (count - working_on_that->size);

                    working_on_that->size = count;

                    HELPER1(pointer, working_on_that)

                    pointer = pointer - FENCE_LENGTH;

                    HELPER2(pointer, count)

                    working_on_that->checksum = calculate_checksum(working_on_that);

                    return pointer;
                }

                working_on_that->size = count;

                working_on_that->checksum = calculate_checksum(working_on_that);

                HELPER1(pointer, working_on_that)

                pointer = pointer - FENCE_LENGTH;

                HELPER2(pointer, count)

                return pointer;
            }
            return memblock;
        }
        heap_free(memblock);
        return NULL;
    }
    return NULL;
} // ok

void heap_free(void *memblock)
{
    if (heap_validate() == 0 && memblock != NULL && get_pointer_type(memblock) == pointer_valid)
    {
        memory_chunk_t *working_on_that;

        working_on_that = (memory_chunk_t *) ((uint8_t *) memblock - sizeof(memory_chunk_t) - FENCE_LENGTH);

        if (working_on_that->prev != NULL)
        {
            if (working_on_that->prev->free != 0)
            {
                if (working_on_that->next != NULL)
                {
                    if (working_on_that->next != NULL)
                    {
                        if (working_on_that->next->free != 0)
                        {
                            working_on_that->free = 1;

                            working_on_that->prev->size = calculateChunkSize(working_on_that->prev) + calculateChunkSize(working_on_that) + working_on_that->next->size + 2 * sizeof(memory_chunk_t) + 4 * FENCE_LENGTH;

                            working_on_that->prev->next = working_on_that->next->next;

                            working_on_that->next->next->prev = working_on_that->prev;

                            working_on_that->next->next->checksum = calculate_checksum(working_on_that->next->next);

                            working_on_that->prev->checksum = calculate_checksum(working_on_that->prev);
                        }
                        else
                        {
                            working_on_that->free = 1;

                            working_on_that->prev->size = calculateChunkSize(working_on_that->prev) + sizeof(memory_chunk_t) + calculateChunkSize(working_on_that) + 2 * FENCE_LENGTH;

                            working_on_that->prev->next = working_on_that->next;

                            working_on_that->next->prev = working_on_that->prev;

                            working_on_that->next->checksum = calculate_checksum(working_on_that->next);

                            working_on_that->prev->checksum = calculate_checksum(working_on_that->prev);
                        }
                    }
                }
                else
                {
                    working_on_that->free = 1;

                    working_on_that->checksum = calculate_checksum(working_on_that);

                    if (working_on_that->prev->prev != NULL)
                    {
                        working_on_that->prev->prev->next = NULL;

                        working_on_that->prev->prev->checksum = calculate_checksum(working_on_that->prev->prev);

                        size_t little_punk = (sizeof(memory_chunk_t) * 2 + 4 * FENCE_LENGTH + working_on_that->size + working_on_that->prev->size);

                        custom_sbrk(-(little_punk));

                        memory_manager.memory_size = memory_manager.memory_size - (little_punk);

                        if (memory_manager.memory_size == 0)
                        {
                            memory_manager.first_memory_chunk = NULL;
                        }

                        working_on_that = NULL;

                        return;
                    }

                    custom_sbrk(-(memory_manager.memory_size));

                    memory_manager.memory_size = 0;

                    memory_manager.first_memory_chunk = NULL;
                }
            }
            else
            {
                if (working_on_that->next != NULL)
                {
                    if (working_on_that->next != NULL)
                    {
                        if (working_on_that->next->free != 0)
                        {
                            working_on_that->free = 1;

                            working_on_that->size = calculateChunkSize(working_on_that) + working_on_that->next->size + sizeof(memory_chunk_t) + 2 * FENCE_LENGTH;

                            working_on_that->next->next->prev = working_on_that;

                            working_on_that->next->next->checksum = calculate_checksum(working_on_that->next->next);

                            working_on_that->next = working_on_that->next->next;

                            working_on_that->checksum = calculate_checksum(working_on_that);
                        }
                        else
                        {
                            working_on_that->free = 1;

                            working_on_that->size = calculateChunkSize(working_on_that);

                            working_on_that->checksum = calculate_checksum(working_on_that);
                        }
                    }
                }
                else
                {
                    working_on_that->free = 1;

                    working_on_that->checksum = calculate_checksum(working_on_that);

                    working_on_that->prev->next = NULL;

                    working_on_that->prev->checksum = calculate_checksum(working_on_that->prev);

                    size_t little_punk = sizeof(memory_chunk_t) + 2 * FENCE_LENGTH + working_on_that->size;

                    custom_sbrk(-(little_punk));

                    memory_manager.memory_size -= (little_punk);

                    if (memory_manager.memory_size == 0)
                    {
                        memory_manager.first_memory_chunk = NULL;
                    }

                    working_on_that = NULL;
                }
            }
        } else
        {
            if (working_on_that->next != NULL)
            {
                if (working_on_that->next != NULL)
                {
                    if (working_on_that->next->free != 0)
                    {
                        working_on_that->free = 1;

                        working_on_that->size = calculateChunkSize(working_on_that) + sizeof(memory_chunk_t) + working_on_that->next->size + 2 * FENCE_LENGTH;

                        working_on_that->next->next->prev = working_on_that;

                        working_on_that->next->next->checksum = calculate_checksum(working_on_that->next->next);

                        working_on_that->next = working_on_that->next->next;

                        working_on_that->checksum = calculate_checksum(working_on_that);
                    }
                    else
                    {
                        working_on_that->free = 1;

                        working_on_that->size = calculateChunkSize(working_on_that);

                        working_on_that->checksum = calculate_checksum(working_on_that);
                    }
                }
            }
            else
            {
                working_on_that->free = 1;

                working_on_that->checksum = calculate_checksum(working_on_that);

                size_t little_punk = memory_manager.memory_size;

                custom_sbrk(-(little_punk));

                memory_manager.memory_size = memory_manager.memory_size - (little_punk);

                memory_manager.first_memory_chunk = NULL;

                working_on_that = NULL;
            }
        }
    }
} // ok

size_t heap_get_largest_used_block_size(void)
{
    if (heap_validate() == 0)
    {
        if (memory_manager.first_memory_chunk != NULL)
        {
            size_t length = 0;

            memory_chunk_t *working_on_that;

            working_on_that = memory_manager.first_memory_chunk;

            for (; working_on_that != NULL;)
            {
                if (working_on_that->free == 0 && working_on_that->size > length)
                {
                    length = working_on_that->size;
                }
                working_on_that = working_on_that->next;
            }
            return length;
        }
        return 0;
    }
    return 0;
} // ok

enum pointer_type_t get_pointer_type(const void *const pointer)
{
    if (pointer != NULL)
    {
        if (heap_validate() == 0)
        {
            memory_chunk_t *temporary_chunk;

            temporary_chunk = memory_manager.first_memory_chunk;

            uint8_t *temporary_pointer;

            for (; temporary_chunk != NULL;)
            {
                temporary_pointer = (uint8_t *) temporary_chunk;

                for (unsigned long i = 0; i < sizeof(memory_chunk_t); ++i, temporary_pointer++)
                {
                    if (pointer == temporary_pointer)
                    {
                        return temporary_chunk->free == 1 ? pointer_unallocated : pointer_control_block;
                    }
                }

                for (int i = 0; i < FENCE_LENGTH; ++i, temporary_pointer++)
                {
                    if (pointer == temporary_pointer)
                    {
                        return temporary_chunk->free == 1 ? pointer_unallocated : pointer_inside_fences;
                    }
                    if (pointer == temporary_pointer + temporary_chunk->size + FENCE_LENGTH)
                    {
                        return temporary_chunk->free == 1 ? pointer_unallocated : pointer_inside_fences;
                    }
                }
                if (pointer != temporary_pointer)
                {
                    for (unsigned long i = 1; i <= temporary_chunk->size; ++i, temporary_pointer++)
                    {
                        if (pointer == temporary_pointer)
                        {
                            return temporary_chunk->free == 1 ? pointer_unallocated : pointer_inside_data_block;
                        }
                    }

                    temporary_chunk = temporary_chunk->next;

                    continue;
                }
                return temporary_chunk->free == 1 ? pointer_unallocated : pointer_valid;
            }
            return pointer_unallocated;
        }
        return pointer_heap_corrupted;
    }
    return pointer_null;
} // ok

int heap_validate(void)
{
    if (memory_manager.memory_start != NULL)
    {
        if (memory_manager.memory_size == 0 || memory_manager.first_memory_chunk != NULL)
        {
            if (memory_manager.memory_size != 0 || memory_manager.first_memory_chunk != NULL)
            {
                memory_chunk_t *working_on_that;

                working_on_that = memory_manager.first_memory_chunk;

                for (; working_on_that != NULL;)
                {
                    if (working_on_that->checksum == calculate_checksum(working_on_that))
                    {
                        working_on_that = working_on_that->next;
                        continue;
                    }
                    return 3;
                }

                working_on_that = memory_manager.first_memory_chunk;

                int helper = 1;

                for (; working_on_that != NULL; )
                {
                    if (working_on_that->free == 0)
                    {
                        uint8_t *pointer;

                        pointer = (uint8_t *) working_on_that + sizeof(memory_chunk_t);

                        char *to_work = (char *) pointer;

                        for (int i = 0; i < FENCE_LENGTH; ++i, to_work++)
                        {
                            if (*to_work == *(fence_value + i))
                            {
                                if (*(to_work + working_on_that->size + FENCE_LENGTH) == *(fence_value + i))
                                {
                                    continue;
                                }
                                return 1;
                            }
                            return 1;
                        }
                    }

                    helper = helper + 1;

                    working_on_that = working_on_that->next;
                }
                return 0;
            }
            return 0;
        }
        return 3;
    }
    return 2;
} // ok

int calculate_checksum(void *work_chunk)
{
    if (work_chunk != NULL)
    {
        memory_chunk_t *working_on_that_pointer;

        working_on_that_pointer = (memory_chunk_t *) work_chunk;

        int length;

        length = (int) ((uint8_t *) &working_on_that_pointer->checksum - (uint8_t *) work_chunk);

        uint8_t *pointer = (uint8_t *) work_chunk;

        int counter = 0;

        for (int i = 0; i < length; ++i)
        {
            counter = counter + *(pointer + i);
        }

        return counter;
    }

    return -1;
} //ok
