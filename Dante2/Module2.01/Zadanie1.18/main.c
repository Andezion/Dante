#include <stdio.h>
#include <ctype.h>

int main()
{
    char name[31];

    printf("Enter name: ");
    scanf("%30[^\n]",name);

    FILE *file;
    file = fopen(name, "rb");
    if(!file)
    {
        printf("COULDN'T OPEN FILE");
        return 4;
    }

    while(getchar() != '\n');

    int temp;

    fseek(file, 0, SEEK_SET);

    int pointer = 0;
    while((temp = getc(file)) != EOF)
    {
        pointer = 1;
    }
    if(pointer == 0)
    {
        printf("NOTHING TO SHOW");
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    while ((temp = getc(file)) != EOF)
    {
        temp = toupper(temp);
        putchar(temp);
    }

    fclose(file);
    return 0;
}
