#include <stdio.h>
#include <string.h>

#define DISPLAY_BITS(value) for (int i = 63; i >= 0; --i) { printf("%lu", (num >> i) & 1); }

void inverse_bits(void* ptr, size_t offset, size_t count);
void show(const void* ptr, size_t count);

int main()
{
    char array[100];

    printf("Enter: ");
    scanf("%100[^\n]",array);
    size_t size = strlen(array);

    printf("\n");

    show(array, size);
    printf("00");

    printf("\n");

    inverse_bits(array, 0, size);

    show(array, size);
    printf("ff");

    return 0;
}

void inverse_bits(void* ptr, size_t offset, size_t count)
{
    if(ptr != NULL || count < 1)
    {
        char *pointer = (char *) ptr;
        for(size_t i = offset; i < count + offset; i++)
        {
            *(pointer + i * sizeof(char)) = ~(*(pointer + i * sizeof(char)));
        }
    }
}

void show(const void *ptr, size_t count)
{
    if(ptr == NULL)
    {
        return;
    }

    unsigned char letter;
    char *pointer = (char *) ptr;

    for(size_t i = 0; i < count; i++)
    {
        letter = *(pointer + i * sizeof(char));
        printf("%02x ", letter);
    }
}
