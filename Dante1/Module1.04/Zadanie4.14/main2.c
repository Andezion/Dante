#include <stdio.h>

int is_non_monotonic(const int a, const int b, const int c)
{
    return (a < b && b > c) || (a > b && b < c);
}

int main(void)
{
    int arr[2000];
    int size = 0;
    printf("Enter numbers:\n");
    for (int i = 0; i < 1000; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        if (arr[i] == 0)
        {
            break;
        }

        size++;
    }

    int max_length = 0;
    int count = 0;
    int starts[1000];

    for (int start = 0; start < size - 2; start++)
    {
        int length = 2;

        while (start + length < size && is_non_monotonic( arr[start + length - 2],arr[start + length - 1],arr[start + length]))
        {
            length++;
        }

        if (length < 3)
            continue;

        if (length > max_length)
        {
            max_length = length;
            count = 0;
        }

        if (length == max_length)
        {
            starts[count++] = start;
        }
    }

    if (max_length == 0)
    {
        printf("0\n0\n");
        return 0;
    }

    printf("%d\n%d\n", max_length, count);

    for (int i = 0; i < count; i++)
    {
        printf("%d -", starts[i]);

        for (int j = 0; j < max_length; j++)
        {
            printf(" %d", arr[starts[i] + j]);
        }

        printf("\n");
    }


    return 0;
}
