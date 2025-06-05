#include <stdio.h>

void my_ltoa_rec(unsigned long long a, char tab[], int start_index)
{
    if(a == 0)
    {
        tab[start_index] = '\0';
        return;
    }
    my_ltoa_rec(a / 10, tab, start_index + 1);
    tab[start_index] = (a % 10) + '0';
}

int main()
{
    unsigned long long num;
    char tab[21];

    printf("Enter: ");
    int check = scanf("%llu",&num);
    if(check != 1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    my_ltoa_rec(num, tab, 0);

    printf("\n%s\n",tab);

    return 0;
}
