#include <stdio.h>"

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <=0 )
    {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        int check = scanf("%d",&vec[i]);
        if (check != 1)
        {
            return -1;
        }
        if (vec[i] == stop_value)
        {
            break;
        }
        count++;
    }
    return count;
}

int max(const int arr[], int size)
{
    if(size <= 0)
    {
        return -1;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int temp = max(arr + 1, size - 1);
    if (arr[0] > temp)
    {
        return arr[0];
    }
    else
    {
        return temp;
    }
}

int main()
{
    int vector[150];
    printf("Enter: ");

    int size = read_vector(vector, 150, -1);
    if(size == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    int res = max(vector, size);
    if(res == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    printf("%i\n",res);

    return 0;
}
