#include <stdio.h>

int main(void)
{
    int arr[200];
    int size = 0;
    printf("Enter numbers:\n");
    for (int i = 0; i < 100; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if (arr[i] == -1)
        {
            break;
        }

        size++;
    }

    if (size < 2)
    {
        printf("Not enough data available");
        return 2;
    }

    int result = 1;
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - i - 1])
        {
            result = 0;
            break;
        }
    }

    if (result == 0) printf("NIE");
    else printf("TAK");

    return 0;
}
