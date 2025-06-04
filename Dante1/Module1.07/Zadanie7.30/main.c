#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checker(const int lotto[], int size, int num)
{
    for(int i = 0; i < size; i++)
    {
        if(lotto[i] == num)
        {
            return 0;
        }
    }
    return 1;
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

int generate(int lotto[], int N, int start, int end)
{
    if(start > end)
    {
        return -1;
    }

    if(end - start + 1 < N)
    {
        return -1;
    }

    int point = 0;
    int i = 0;
    while(point != N)
    {
        lotto[i] = start + rand() % (end - start + 1);
        int check = checker(lotto, i, lotto[i]);
        if(check == 1)
        {
            point++;
            i++;
        }
    }

    return 0;
}

int vector_max_norm(const int tab[], int size);
int vector_sum(const int tab[], int size);

int main()
{
    int start;

    printf("Enter: ");
    int check1 = scanf("%i",&start);
    if(check1 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int end;

    printf("\nEnter: ");
    int check2 = scanf("%i",&end);
    if(check2 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int N;

    printf("\nEnter: ");
    int check3 = scanf("%i",&N);
    if(check3 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    if(N == 0 || N > 100)
    {
        printf("\nIncorrect input data\n");
        return 2;
    }

    int lotto[100];
    int check4 = generate(lotto, N, start, end);
    if(check4 != 0)
    {
        printf("\nIncorrect input data\n");
        return 2;
    }

    display_vector(lotto, N);

    int check5 = vector_max_norm(lotto, N);
    if(check5 == 0)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\nResult: %i",check5);

    int check6 = vector_sum(lotto, N);
    if(check6 == 0)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\nResult: %i",check6);

    return 0;
}

int vector_max_norm(const int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 0;
    }

    int max = abs(tab[0]);
    for(int i = 1; i < size; i++)
    {
        if(abs(tab[i]) > max)
        {
            max = abs(tab[i]);
        }
    }
    return max;
}

int vector_sum(const int tab[], int size)
{
    if(tab == NULL || size <= 0)
    {
        return 0;
    }

    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum = sum + tab[i];
    }
    return sum;
}
