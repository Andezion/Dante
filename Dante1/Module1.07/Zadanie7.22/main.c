#include <stdio.h>

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || size <= 0 || second == NULL || size2 <= 0 || dest == NULL || size3 <= 0 )
    {
        return -1;
    }
    if (size + size2 > size3)
    {
        return -2;
    }

    for (int i = 0; i < size; i++)
    {
        dest[i] = first[i];
    }
    for (int i = 0; i < size2; i++)
    {
        dest[size + i] = second[i];
    }

    return size + size2;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || size <= 0 || second == NULL || size2 <= 0 || dest == NULL || size3 <= 0)
    {
        return -1;
    }
    if (size + size2 != size3)
    {
        return -2;
    }

    for (int i = 0; i < size2; i++)
    {
        dest[i] = second[i];
    }
    for (int i = 0; i < size; i++)
    {
        dest[size2 + i] = first[i];
    }

    return size + size2;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || size <= 0 || second == NULL || size2 <= 0 || dest == NULL || size3 <= 0)
    {
        return -1;
    }
    if (size + size2 != size3)
    {
        return -2;
    }

    int plz_work = 0;
    int temp;

    if (size < size2)
    {
        temp = size;
    }
    else
    {
        temp = size2;
    }

    for (int i = 0; i < temp; i++)
    {
        dest[plz_work] = first[i];
        plz_work++;
        dest[plz_work] = second[i];
        plz_work++;
    }

    for (int i = temp; i < size; i++)
    {
        dest[plz_work] = first[i];
        plz_work++;
    }

    for (int i = temp; i < size2; i++)
    {
        dest[plz_work] = second[i];
        plz_work++;
    }

    return plz_work;
}

int read_vector(int vec[], int size, int stop_value)
{
    if (vec == NULL || size <= 0)
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        int check = scanf("%i",&vec[i]);
        if (check != 1)
        {
            return -2;
        }
        if (vec[i] == stop_value)
        {
            break;
        }
        count++;
    }
    return count;
}

void display_vector(const int vec[], int size)
{
    if (vec == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i ",vec[i]);
    }
}

int main()
{
    int first[50];
    printf("Enter: ");
    int size = read_vector(first, 50, 0);
    if(size == -1 || size == -2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size < 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    while(getchar() != '\n');

    int second[50];
    printf("\nEnter: ");
    int size2 = read_vector(second, 50, 0);
    if(size2 == -1 || size2 == -2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(size2 < 1)
    {
        printf("\nNot enough data available\n");
        return 2;
    }

    while(getchar() != '\n');

    printf("\n");

    int dest[100];
    int size3 = size + size2;

    display_vector(first, size);

    printf("\n");

    display_vector(second, size2);

    printf("\n");

    if(size3 > 50)
    {
        printf("\nOutput buffer is too small\n");
        return 0;
    }

    int check1 = concat_begin(first, size, second, size2, dest, size3);
    if(check1 == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(check1 == -2)
    {
        printf("\nOutput buffer is too small\n");
        return 1;
    }
    display_vector(dest, size3);

    printf("\n");

    int check2 = concat_end(first, size, second, size2, dest, size3);
    if(check2 == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(check2 == -2)
    {
        printf("\nOutput buffer is too small\n");
        return 1;
    }
    display_vector(dest, size3);

    printf("\n");

    int check3 = concat_zip(first, size, second, size2, dest, size3);
    if(check3 == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(check3 == -2)
    {
        printf("\nOutput buffer is too small\n");
        return 1;
    }
    display_vector(dest, size3);

    printf("\n");

    return 0;
}
