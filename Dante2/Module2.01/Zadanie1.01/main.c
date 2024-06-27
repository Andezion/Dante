#include <stdio.h>

int main()
{
    FILE *file;
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]",name);

    file = fopen(name, "r");
    if(!file)
    {
        printf("Couldn't open file\n");
        return 4;
    }

    int pointer = 0;
    int temporary;

    while((temporary = getc(file)) != EOF)
    {
        printf("%c",temporary);
        //putchar(temporary);
        pointer = 1;
    }

    if(!pointer)
    {
        printf("Nothing to show\n");
    }

    fclose(file);

    return 0;
}
