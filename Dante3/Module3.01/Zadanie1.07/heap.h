#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

#define XD 4000

#define HELPER2(name, size)     for (int i = 0; i < FENCE_LENGTH; ++i, name++) \
{*(char *) (name) = *(fence_value + i);    \
*(char *) (name+size+FENCE_LENGTH) = *(fence_value + i);\
}                                          \

#define HELPER3(x)    ((((intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH))+(ALIGNMENT-1))&~(ALIGNMENT-1))
#define HELPER4(x)    (ALIGN(x) - (intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH))

#define HELPER5(x) (((intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH) & (intptr_t) (ALIGNMENT - 1)))

#define HELPER1(ptr, chunk) uint8_t *ptr=(uint8_t*)(chunk); \
(ptr)+=sizeof(memory_chunk_t);    \
(ptr)+=FENCE_LENGTH;\

typedef struct memory_manager_t
{
    void *memory_start;
    size_t memory_size;
    struct memory_chunk_t *first_memory_chunk;
} memory_manager_t;

typedef struct memory_chunk_t
{
    struct memory_chunk_t *prev;
    struct memory_chunk_t *next;

    size_t size;

    int free;
    int checksum;
} memory_chunk_t;

typedef enum pointer_type_t
{
    pointer_null,
    pointer_heap_corrupted,
    pointer_control_block,
    pointer_inside_fences,
    pointer_inside_data_block,
    pointer_unallocated,
    pointer_valid
} pointer_type_t;

int calculate_checksum(void *work_chunk);

int heap_setup(void);
void heap_clean(void);

void *heap_malloc(size_t size);
void *heap_calloc(size_t number, size_t size);
void *heap_realloc(void *memblock, size_t count);
void heap_free(void *memblock);

size_t heap_get_largest_used_block_size(void);
enum pointer_type_t get_pointer_type(const void *const pointer);
int heap_validate(void);

#endif //HEAP_H
