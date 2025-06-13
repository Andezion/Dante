#include <stdio.h>
#include "letter_changer.h"

int main()
{
    char txt[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",txt);

    while(getchar() != '\n');

    char c;
    int pointer = 0;
    while(pointer != 1)
    {
        printf("Enter: ");

        scanf("%c",&c);

        while(getchar() != '\n');

        if(c == 's' || c == 'b' || c == 'B' || c == 'S')
        {
            break;
        }
        if(c != 'b' && c != 's' && c != 'B' && c != 'S')
        {
            printf("Incorrect input\n");
            continue;
        }
        pointer = 1;
    }

    char *result = change_letter_size(txt,c);
    if(result == NULL)
    {
        printf("\nIncorrect input111\n");
        return 1;
    }

    printf("\n%s",txt);

    return 0;
}
