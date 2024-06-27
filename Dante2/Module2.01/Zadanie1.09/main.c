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
    int counter = 0;

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

    int number;
    fscanf(file, "%i", &number);

    if(number < 1)
    {
        fclose(file);
        printf("File corrupted");
        return 6;
    }

    while(fscanf(file, "%i", &pointer_of_number) == 1 && counter < number)
    {
        suma = suma + pointer_of_number;
        counter++;
    }

    if(counter < number)
    {
        fclose(file);
        printf("File corrupted");
        return 6;
    }

    printf("%i\n%f\n",suma,(float)suma / (float)counter);

    fclose(file);
    return 0;
}
