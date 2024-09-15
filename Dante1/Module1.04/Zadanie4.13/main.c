#include <stdio.h>

int main()
{
    int error;
    int array[3000];
    int size_of_array = 0;

    printf("Enter array: ");

    for(int i = 0; i < 3000; i++)
    {
        error = scanf("%i", &array[i]);
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(array[i] == 0)
        {
            break;
        }
        size_of_array++;
    }
    if(size_of_array > 1000)
    {
        size_of_array = 1000;
    }

    if (size_of_array == 0)
    {
        printf("\n0\n0\n");
        return 0;
    }

    if (size_of_array == 1)
    {
        printf("\n0\n0");
        return 0;
    }

    int max = 0, counter = 0, temp = 1;
    int some_shit[1000] = {0}, storage_for_index[1000] = {0};

    for (int i = 1; i < size_of_array; ++i)
    {
        if (array[i] > array[i - 1])
        {
            temp++;
        }
        else
        {
            if (temp > max)
            {
                max = temp;
                counter = 1;
                some_shit[0] = temp;
                storage_for_index[0] = i - temp;
            }
            else if (temp == max)
            {
                some_shit[counter] = temp;
                storage_for_index[counter] = i - temp;
                counter++;
            }
            temp = 1;
        }
    }

    if (temp > max)
    {
        max = temp;
        counter = 1;
        some_shit[0] = temp;
        storage_for_index[0] = size_of_array - temp;
    }
    else if (temp == max)
    {
        some_shit[counter] = temp;
        storage_for_index[counter] = size_of_array - temp;
        counter++;
    }
    if (max < 2)
    {
        printf("\n0\n0\n");
        return 0;
    }

    printf("\n%i\n%i\n", max, counter);
    for (int i = 0; i < counter; i++)
    {
        printf("%i -", storage_for_index[i]);
        for (int j = 0; j < some_shit[i]; j++)
        {
            printf(" %i", array[storage_for_index[i] + j]);
        }
        printf("\n");
    }

    return 0;
}
