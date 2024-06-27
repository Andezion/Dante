#include <stdio.h>
#include <string.h>

int checker(const char *filename)
{
    int size = 0;
    while(*(filename + size) != '\0')
    {
        size++;
    }

    if(!((*(filename + size - 4) == '.') && (*(filename + size - 3) == 'b') && (*(filename + size - 2) == 'm') && (*(filename + size - 1) == 'p')))
    {
        return 0;
    }

    return 1;
}

int main()
{
    char filename[51];
    printf("Enter: ");
    scanf("%30[^\n]", filename);

    if(checker(filename) == 0)
    {
        printf("Unsupported File Format");
        return 7;
    }

    FILE *file;
    file = fopen(filename, "r");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    int k;
    for(k = (int)strlen(filename); k >= 0; k--)
    {
        *(filename + k + 5) = *(filename + k);
    }
    *(filename + k + 5) = '_', *(filename + k + 4) = 'y', *(filename + k + 3) = 'p', *(filename + k + 2) = 'o', *(filename + k + 1) = 'c';

    FILE *new_file;
    new_file = fopen(filename, "w");
    if(!new_file)
    {
        printf("Couldn't create file");
        fclose(file);
        return 5;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0 , SEEK_SET);

    for(int i = 0; i < size; i++)
    {
        fputc(fgetc(file), new_file);
    }

    printf("File saved");

    fclose(file);
    fclose(new_file);

    return 0;
}
