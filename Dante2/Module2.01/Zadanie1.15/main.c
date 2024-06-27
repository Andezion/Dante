#include <stdio.h>

int main()
{
    char name[31];

    printf("Enter name: ");
    scanf("%30[^\n]",name);

    FILE *file;
    file = fopen(name, "rb");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    while(getchar() != '\n');
    printf("\n");

    int temp;

    fseek(file, 0, SEEK_SET);

    int pointer = 0;
    while((temp = getc(file)) != EOF)
    {
        pointer = 1;
    }
    if(pointer == 0)
    {
        printf("%i", 0);
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    int counter = 1;
    printf("%i. ", counter);

    while ((temp = getc(file)) != EOF)
    {
        putchar(temp);
        if (temp == '\n')
        {
            counter++;
            printf("%i. ", counter);
        }
    }

    printf("\n%i",counter);

    fclose(file);
    return 0;
}
