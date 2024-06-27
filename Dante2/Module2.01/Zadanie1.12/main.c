#include <stdio.h>

int main()
{
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]", name);

    while(getchar() != '\n');

    FILE *file = fopen(name, "rb");
    if (!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    float suma = 0;
    float number = 0;
    int counter = 0;


    while (fread(&number, sizeof(float), 1, file) == 1 && counter < 100)
    {
        suma = suma + number;
        counter++;
    }

    if (counter < 100)
    {
        fclose(file);
        printf("File corrupted");
        return 6;
    }

    float middle = suma / (float)counter;

    fclose(file);

    char name_new[31];
    FILE *new;

    printf("Enter: ");
    scanf("%30[^\n]", name_new);

    while(getchar() != '\n');

    new = fopen(name_new, "wb");
    if (!new)
    {
        printf("Couldn't create file");
        return 5;
    }

    //fprintf(new, "%f\n%f", suma, middle);

    fwrite(&suma, sizeof(int), 1, new);
    fwrite(&middle, sizeof(float), 1, new);

    fclose(new);
    printf("File saved\n");

    return 0;
}
