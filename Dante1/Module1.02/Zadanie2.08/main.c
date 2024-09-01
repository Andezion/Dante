#include <stdio.h>

int main()
{
    int number;
    char letter;

    printf("Enter smth plz: ");

    int check = scanf("%c%i",&letter,&number);
    if(check != 2)
    {
        printf("Incorrect input");
        return 1;
    }

    if(letter >= 'a' && letter <= 'h' && number >= 1 && number <= 8)
    {
        if((letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g') && (number % 2 == 0))
        {
            printf("White");
        }
        if((letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h') && (number % 2 == 1))
        {
            printf("White");
        }
        if((letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g') && (number % 2 != 0))
        {
            printf("Black");
        }
        if((letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h') && (number % 2 == 0))
        {
            printf("Black");
        }
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
}
