#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int counter = 10;
    int number = 0 + rand() % 101;

    while(counter != 0)
    {
        int temp;

        printf("\nEnter number: ");

        int check = scanf("%i",&temp);
        if(check != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        counter--;

        if(temp == number)
        {
            printf("wygrales");
            break;
        }
        else if(temp > number)
        {
            printf("\nza duzo");
        }
        else
        {
            printf("\nza malo");
        }
    }
    if(counter == 0)
    {
        printf("\nprzegrales");
    }

    return 0;
}
