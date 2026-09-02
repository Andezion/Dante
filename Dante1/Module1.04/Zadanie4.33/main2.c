#include <stdio.h>

int main(void)
{
    int arr[10];
    int counter = 0;
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        if (arr[i] % 2 == 0)
        {
            counter++;
        }
    }

    if (counter != 4)
    {
        printf("Incorrect input data");
        return 2;
    }

    int arr2[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            int index = 0;
            while (arr2[index] != 0)
            {
                index += 3;
            }
            arr2[index] = arr[i];
        }
        else
        {
            int index = 1;
            while (arr2[index] != 0 || index % 3 == 0)
            {
                index++;
            }
            arr2[index] = arr[i];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}
