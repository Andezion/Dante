#include <stdio.h>
#include <ctype.h>

int main()
{
    char l1,l2,l3,l4,l5;

    printf("Enter: ");

    scanf("%c%c%c%c%c",&l1,&l2,&l3,&l4,&l5);

    printf("\n");

    l1 = toupper(l1);
    l2 = toupper(l2);
    l3 = toupper(l3);
    l4 = toupper(l4);
    l5 = toupper(l5);

    printf("%c%c%c%c%c",l1,l2,l3,l4,l5);
    
    return 0;
}
