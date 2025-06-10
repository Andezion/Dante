#include "storage.h"
#include <stdint.h>
#include <stddef.h>

void memory_init(void *address, size_t size)
{
    if (address == NULL || size <= sizeof(struct memory_chunk_t))
        return;

    memory_manager.memory_start = address;
    memory_manager.memory_size = size;
    memory_manager.first_memory_chunk = NULL;
}

void *memory_malloc(size_t size)
{
    if(size > memory_manager.memory_size - sizeof(struct memory_chunk_t) || size == 0)
    {
        return NULL;
    }

    struct memory_chunk_t *temporary = memory_manager.first_memory_chunk;

    if(memory_manager.first_memory_chunk == NULL)
    {
        temporary = (void*)(memory_manager.memory_start);
        memory_manager.first_memory_chunk = temporary;

        temporary->prev = NULL;
        temporary->next = NULL;

        temporary->free = 0;

        temporary->size = size;

        return (void*)((uint8_t*)temporary + sizeof(struct memory_chunk_t));
    }

    size_t size_to_use = 0;
    while(temporary->next != NULL)
    {
        if(temporary->free == 1 && temporary->size >= size + sizeof(struct memory_chunk_t))
        {
            break;
        }
        size_to_use = size_to_use + temporary->size + sizeof(struct memory_chunk_t);
        temporary = temporary->next;
    }

    if(temporary->size >= size + sizeof(struct memory_chunk_t) && temporary->free == 1)
    {
        temporary->free = 0;

        temporary->size = size;

        return (void*)((uint8_t*)temporary + sizeof(struct memory_chunk_t));
    }

    size_to_use += temporary->size + sizeof(struct memory_chunk_t) + size;

    if(size_to_use > memory_manager.memory_size - sizeof(struct memory_chunk_t)) return NULL;

    if(temporary->next == NULL)
    {
        struct memory_chunk_t* next = (void*)((uint8_t*)temporary + sizeof(struct memory_chunk_t) + temporary->size);

        next->prev = temporary;
        next->next = NULL;

        next->free = 0;

        next->size = size;

        temporary->next = next;

        temporary = next;

        return (void*)((uint8_t*)temporary + sizeof(struct memory_chunk_t));
    }

    return NULL;
}

void memory_free(void *address)
{
    if(address == NULL)
    {
        return;
    }

    struct memory_chunk_t *temporary = (struct memory_chunk_t *)((uint8_t *)address - sizeof(struct memory_chunk_t));

    if((temporary->free != 1 && temporary->free != 0) || temporary->size == 0)
    {
        return;
    }

    int found = 0;
    struct memory_chunk_t *to_delete_methods = memory_manager.first_memory_chunk;

    for(;to_delete_methods != NULL;)
    {
        if(temporary == to_delete_methods)
        {
            found = 1;

            break;
        }

        to_delete_methods = to_delete_methods->next;
    }

    if(found == 0)
    {
        return;
    }

    if(temporary->next != NULL)
    {
        size_t new_size = (uint8_t *)temporary->next - ((uint8_t *)temporary + sizeof(struct memory_chunk_t));

        temporary->size = new_size;
    }

    temporary->free = 1;
    if(temporary->prev != NULL && temporary->prev->free == 1)
    {
        struct memory_chunk_t *before = temporary->prev;
        before->next = temporary->next;

        if(temporary->next != NULL)
        {
            temporary->next->prev = before;
        }

        before->size = before->size + temporary->size + sizeof(struct memory_chunk_t);
        temporary = before;
    }

    if(temporary->next != NULL && temporary->next->free == 1)
    {
        struct memory_chunk_t* next = temporary->next;
        temporary->next = next->next;

        if(next->next != NULL)
        {
            next->next->prev = temporary;
        }

        temporary->size = temporary->size + next->size + sizeof(struct memory_chunk_t);
    }

    if(temporary->next == NULL && temporary->prev != NULL)
    {
        temporary->prev->next = NULL;
    }

    if(temporary->next == NULL && memory_manager.first_memory_chunk == temporary)
    {
        memory_manager.first_memory_chunk = NULL;
    }
}
