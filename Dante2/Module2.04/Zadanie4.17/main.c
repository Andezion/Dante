#include <stdio.h>
#include <stdlib.h>

int sort(int *data, int size)
{
    if(data == NULL || size <= 0)
    {
        return 1;
    }

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(*(data + j) > *(data + j + 1))
            {
                int temp = *(data + j);
                *(data + j) = *(data + j + 1);
                *(data + j + 1) = temp;
            }
        }
    }

    return 0;
}

void display_vector(const int *data, int size)
{
    if(data == NULL || size <= 0)
    {
        return;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%i ",*(data + i));
    }
}

int main()
{
    int *data = NULL;

    int some_shit = 0;
    int size = 0;

    int input;
    int error;

    printf("Enter: ");
    while (1)
    {
        error = scanf("%i", &input);
        if (error != 1)
        {
            printf("Incorrect input");

            if (data != NULL)
            {
                free(data);
            }

            return 1;
        }

        if (input == 0)
        {
            break;
        }

        if (size >= some_shit)
        {
            int temp_helper = some_shit + 40;

            int *temp = realloc(data, temp_helper * sizeof(int));
            if (temp == NULL)
            {
                printf("Failed to allocate memory");

                if (data != NULL)
                {
                    free(data);
                }

                return 8;
            }

            data = temp;
            some_shit = temp_helper;
        }

        *(data + size) = input;
        size++;
    }

    if (size == 0)
    {
        printf("Nothing to show");
    }

    printf("\n");

    error = sort(data, size);
    if(error != 0)
    {
        printf("Incorrect input");

        if (data != NULL)
        {
            free(data);
        }

        return 1;
    }

    display_vector(data, size);

    free(data);
    return 0;
}
