#include <stdio.h>
#include <stdint.h>

int count_bits(const void *ptr, size_t offset, size_t count);

int main()
{
    char filename[101];
    printf("Enter your filename: ");
    scanf("%100[^\n]", filename);

    FILE *file = fopen(filename, "rb");
    if(file == NULL)
    {
        printf("Unable to open the file");
        return 1;
    }

    char storage[1000];
    int letter;
    int iterator = 0;
    while((letter = fgetc(file)) != EOF)
    {
        *(storage + iterator) = letter;
        iterator++;
    }
    *(storage + iterator) = '\0';
    fclose(file);

    int result = count_bits(storage, 0, iterator);
    if(result == -1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%i\n", result);
    return 0;
}

int count_bits(const void* ptr, size_t offset, size_t count)
{
    if(ptr == NULL)
    {
        return -1;
    }

    int result = 0;
    const uint8_t *array = (const uint8_t *) ptr;

    size_t i = offset;
    while(i < count + offset)
    {
        int some_variable = 0;
        uint8_t var = *(array + i);
        while(var > 0)
        {
            if(var % 2 == 1)
            {
                some_variable++;
            }
            var = var / 2;
        }
        result = result + some_variable;
        i++;
    }

    return result;
}
