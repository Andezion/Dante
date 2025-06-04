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

int generate(int lotto[], int N, int start, int end);

int main()
{
    srand(time(NULL));

    int lotto[6] = { 0 };
    /*int N, start, end;

    printf("Enter: ");
    int check1 = scanf("%i",&N);
    if(check1 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\nEnter: ");
    int check2 = scanf("%i",&start);
    if(check2 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\nEnter: ");
    int check3 = scanf("%i",&end);
    if(check3 != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    printf("\n");*/

    int check4 = generate(lotto, 6, 1, 49);
    if(check4 != 0)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    display_vector(lotto, 6);

    return 0;
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
