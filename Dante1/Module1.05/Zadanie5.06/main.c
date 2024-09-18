#include <stdio.h>
#include <string.h>

int main()
{

    char data[11];

    printf("Enter your word: ");
    scanf("%10[^\n]",data);

    int size = (int)strlen(data);
    
    if(data[size - 1] == 'a')
    {
        printf("Imie zenskie");
    }
    else
    {
        printf("Imie meskie");
    }

    return 0;
}
