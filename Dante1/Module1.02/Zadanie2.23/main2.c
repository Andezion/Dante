#include <stdio.h>

int main()
{
    int num;
    char *data[] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};
    printf("Enter: ");

    int check = scanf("%d",&num);

    printf("\n");

    int try = (check == 1) && (num >= 1) && (num <= 12);
    switch(try)
    {
        case 1:
            printf("%s", data[num - 1]);
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
