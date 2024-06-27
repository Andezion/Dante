#include <stdio.h>

int main()
{
    FILE *file;
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]",name);

    file = fopen(name, "r");
    if (file != NULL)
    {
        printf("File already exists!");
        fclose(file);
        return 0;
    }

    file = fopen(name, "w");
    if (!file)
    {
        printf("Couldn't create file");
        return 5;
    }

    printf("File created");

    fclose(file);
    return 0;
}
