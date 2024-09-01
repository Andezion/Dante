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
                case 1:
                    printf("styczen");
                    return 0;
                case 2:
                    printf("luty");
                    return 0;
                case 3:
                    printf("marzec");
                    return 0;
                case 4:
                    printf("kwiecien");
                    return 0;
                case 5:
                    printf("maj");
                    return 0;
                case 6:
                    printf("czerwiec");
                    return 0;
                case 7:
                    printf("lipiec");
                    return 0;
                case 8:
                    printf("sierpien");
                    return 0;
                case 9:
                    printf("wrzesien");
                    return 0;
                case 10:
                    printf("pazdziernik");
                    return 0;
                case 11:
                    printf("listopad");
                    return 0;
                case 12:
                    printf("grudzien");
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
