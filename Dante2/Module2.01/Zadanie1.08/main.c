#include <stdio.h>

int main()
{
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]", name);

    FILE *file = fopen(name, "rb");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    int suma = 0;
    int pointer_of_number;
    char some_helper = 0;

    while(fread(&some_helper, 1, 1, file) != 0)
    {
        if(!((some_helper >= 48 && some_helper <= 57) || some_helper == 13 ||
        some_helper == '\t' || some_helper == '\0' ||
           some_helper == '-' || some_helper == ' ' || some_helper == '\n'))
        {
            fclose(file);
            printf("File corrupted");
            return 6;
        }
    }
    fseek(file, 0, SEEK_SET);

    while(fscanf(file, "%d", &pointer_of_number) == 1)
    {
        suma = suma + pointer_of_number;
    }
    printf("%i",suma);

    fclose(file);
    return 0;
}

