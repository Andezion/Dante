#include <stdio.h>

int main()
{
    FILE *file;
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]",name);

    file = fopen(name, "rb");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    int temp;
    while((temp = fgetc(file)) != EOF)
    {
        printf("%i ", temp);
    }

    fclose(file);
    return 0;
}
