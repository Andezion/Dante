#include <stdio.h>

int main()
{
    char name[31];

    printf("Enter in: ");
    scanf("%30[^\n]", name);

    while(getchar() != '\n');

    FILE *file = fopen(name, "a+");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        fclose(file);
        printf("File corrupted");
        return 6;
    }

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

    char new_file[31];

    printf("Enter out: ");
    scanf("%30[^\n]", new_file);

    while(getchar() != '\n');

    FILE *fileop;
    fileop = fopen(new_file, "a+");
    if(!fileop)
    {
        printf("Couldn't create file");
        fclose(file);
        return 5;
    }

    int suma = 0;
    int number;
    char some_shit_idk;

    while(fscanf(file, "%d%c", &number, &some_shit_idk) == 2) // там блять этот %с ибо пробел даунский нужно обработать как-то
    {
        suma = suma + number;

        if(some_shit_idk == '\n')
        {
            fprintf(fileop, "%i\n", suma);
            suma = 0;
        }
    }

    printf("File saved");
    fclose(file);
    fclose(fileop);
    return 0;
}
