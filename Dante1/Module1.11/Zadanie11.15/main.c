#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sort(char const *ptrs[], int size)
{
    if (ptrs == NULL || size < 1)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (*(ptrs + i) != NULL)
        {
            continue;
        }
        return 1;
    }

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (strcmp(*(ptrs + i), *(ptrs + j)) <= 0)
            {
                continue;
            }
            char const *temp = *(ptrs+i);
            *(ptrs+i) = *(ptrs+j);
            *(ptrs+j) = temp;
        }
    }

    return 0;
}


int main()
{
    int size = 0;
    char *ptrs[11];

    printf("Enter: ");

    for (int i = 0; i < 10; i++)
    {
        *(ptrs + i) = malloc(sizeof(char) * 91);
        for (int j = 0; j < 91; j++)
        {
            *(*(ptrs + i) + j) = '\0';
        }
    }

    while(size < 10)
    {
        scanf("%90[^\n]", *(ptrs + size));

        while(getchar() != '\n');

        if (strcmp(*(ptrs + size++), "") == 0)
        {
            size--;
            break;
        }
    }

    if (size >= 1)
    {

        sort((const char **) ptrs, size);

        for (int i = 0; i < size; i++)
        {
            printf("%s\n", *(ptrs + i));
        }

        for (int i = 0; i < 10; i++)
        {
            free(*(ptrs + i));
        }

        return 0;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            free(*(ptrs + i));
        }

        printf("\nNot enough data available\n");
        return 3;
    }
}
