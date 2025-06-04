#include <stdio.h>

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

int histogram_vector(const int vect[], int size, int out[], int size_out, int min_value, int max_value);
int max_vector(const int vect[], int size);
int min_vector(const int vect[], int size);

int main()
{
    int tab[100];

    printf("Enter: ");

    int size = read_vector(tab, 100, -1);
    if(size < 0)
    {
        printf("Incorrect input");
        return 1;
    }
    if(size < 1)
    {
        printf("Not enough data available");
        return 2;
    }

    for(int i = 0; i < size; i++)
    {
        if(tab[i] < 0 || tab[i] > 20)
        {
            printf("Incorrect input data");
            return 2;
        }
    }

    int tab_out[21];
    int min = min_vector(tab, size);
    int max = max_vector(tab, size);

    int check = histogram_vector(tab, size, tab_out, 21, min, max);
    if(check == -1)
    {
        printf("Incorrect input");
        return 1;
    }

    /*int final[21];
    final[0] = tab_out[19];
    final[1] = tab_out[20];
    for(int i = 2; i < 21; i++)
    {
        final[i] = tab_out[i - 2];
    }*/

    display_vector(tab_out, 21);

    return 0;
}

int histogram_vector(const int vect[], int size, int out[], int size_out, int min_value, int max_value)
{
    if(vect == NULL || out == NULL || size <= 0 || size_out < max_value - min_value + 1 || min_value > max_value)
    {
        return -1;
    }
    
    for(int i = 0; i < size; i++)
    {
        int value = vect[i];

        if(value >= min_value && value <= max_value)
        {
            out[value]++;
        }
    }

    return size_out;
}

int min_vector(const int vect[], int size)
{
    if(vect == NULL || size <= 0)
    {
        return -1;
    }

    int min = 10000;
    for(int i = 0; i < size; i++)
    {
        if(min > vect[i])
        {
            min = vect[i];
        }
    }

    return min;
}
int max_vector(const int vect[], int size)
{
    if(vect == NULL || size <= 0)
    {
        return -1;
    }

    int max = -10000;
    for(int i = 0; i < size; i++)
    {
        if(max < vect[i])
        {
            max = vect[i];
        }
    }

    return max;
}
