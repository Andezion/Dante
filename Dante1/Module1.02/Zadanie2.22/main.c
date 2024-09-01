#include <stdio.h>

int main()
{
    int num;

    printf("Enter: ");

    int check = scanf("%i",&num);

    printf("\n");

    int try = (check == 1);
    switch(try)
    {
        case 1:
            switch (num)
            {
                case 0:
                    printf("zero");
                    return 0;
                case 1:
                    printf("jeden");
                    return 0;
                case 2:
                    printf("dwa");
                    return 0;
                case 3:
                    printf("trzy");
                    return 0;
                case 4:
                    printf("cztery");
                    return 0;
                case 5:
                    printf("piec");
                    return 0;
                case 6:
                    printf("szesc");
                    return 0;
                case 7:
                    printf("siedem");
                    return 0;
                case 8:
                    printf("osiem");
                    return 0;
                case 9:
                    printf("dziewiec");
                    return 0;
                case 10:
                    printf("dziesiec");
                    return 0;
                default:
                    printf("Incorrect input");
                    return 1;
            }
        default:
            printf("Incorrect input");
            return 1;
    }
}
