
#include <stdio.h>

int main()
{

    char data[1000];

    printf("Enter your word: ");
    scanf("%999[^\n]",data);

    while(getchar() != '\n');

    int i = 0;
    while(data[i] != '\0')
    {
        i++;
    }
    if(i == 999)
    {
        printf("\n%i",1000);
    }
    else
    {
        printf("\n%i",i);
    }

    return 0;
}
