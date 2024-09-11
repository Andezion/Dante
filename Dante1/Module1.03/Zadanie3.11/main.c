#include <stdio.h>
#include <math.h>

int main()
{
    float num;

    int pointer = 0;
    while(pointer != 1)
    {
        num = 0;
        printf("Enter: ");

        int check = scanf("%f",&num);

        getchar();

        if(check == 1 && num > 0)
        {
            pointer = 1;
        }
        else
        {
            printf("Incorrect input\n");
            pointer = 0;
        }
    }

    printf("%.3f\n%.3f",2 * M_PI * num, M_PI * num * num);

    return 0;
}
