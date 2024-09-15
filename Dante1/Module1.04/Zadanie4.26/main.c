#include <stdio.h>
#include <stdlib.h>

int main()
{
    int error;

    int array_main[1000];
    int size_of_array_main = 0;
    printf("Enter numbers: ");

    for(int i = 0; i < 1000; i++)
    {
        error = scanf("%i", &array_main[i]);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(array_main[i] == 0)
        {
            break;
        }
        size_of_array_main++;
    }

    int array_support[1000];
    int size_of_array_support = 0;
    printf("\nEnter numbers: ");

    for(int i = 0; i < 1000; i++)
    {
        error = scanf("%i",&array_support[i]);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(array_support[i] == 0)
        {
            break;
        }
        size_of_array_support++;
    }

    if(size_of_array_main > 100)
    {
        size_of_array_main = 100;
    }
    if(size_of_array_main < 2)
    {
        printf("Not enough data available");
        return 2;
    }
    if(size_of_array_support == 0)
    {
        printf("Not enough data available");
        return 2;
    }
    if(size_of_array_support != 2)
    {
        printf("Incorrect input");
        return 1;
    }

    int counter = 0;
    for(int i = 0; i < size_of_array_main - 1; i++)
    {
        if(array_main[i] == array_support[0])
        {
            if(array_main[i + 1] == array_support[1])
            {
                counter++;
            }
        }
    }

    printf("\n%i",counter);
    for(int i = 0; i < size_of_array_main - 1; i++)
    {
        if(array_main[i] == array_support[0])
        {
            if(array_main[i + 1] == array_support[1])
            {
                printf("\n%i", i);
            }
        }
    }

    return 0;
}
