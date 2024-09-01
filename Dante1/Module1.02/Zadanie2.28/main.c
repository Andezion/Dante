
#include <stdio.h>

void Choice(char choice)
{
    printf("You chose ");
    switch(choice)
    {
        case 'C':
            printf("dinner ");
    }
    switch (choice)
    {
        case 'B':
            printf("lunch and dinner ");
    }
    switch (choice)
    {
        case 'A':
            printf("Breakfast, lunch and dinner ");
    }
    printf("as your meal plan.");
}

int main()
{
    char litera;
    printf("wybierz wariant posilku: ");
    switch((scanf("%c",&litera))&&('A'<=litera)&&(litera<='C'))
    {
        case 1: Choice(litera); return 0;
        default: printf("incorrect input\n"); return 1;
    }
}
