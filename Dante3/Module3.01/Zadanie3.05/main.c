#include <stdio.h>
#include "storage.h"

int test1()
{
    char memory[1866];

    memory_init(memory, 1866);

    if(memory_manager.memory_size != 1866)
    {
        return -1;
    }

    if(memory_manager.first_memory_chunk != NULL)
    {
        return -1;
    }

    if(memory_manager.memory_start != memory)
    {
        return -1;
    }

    return 0;
}

int main(void)
{
    printf("Checking...\n");
    if(test1() == 0)
    {
        printf("First test - Success!\n");
    }
    else
    {
        printf("First test - Failed!\n");
    }
    return 0;
}
