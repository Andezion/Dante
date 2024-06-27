#include <stdio.h>
#include <ctype.h>

int checking_if_correct(FILE *file);
int checking_if_number(FILE *file);
int checking_if_true(FILE *file);
int checking_size(FILE *file);

int main()
{
    char data[31];
    printf("Enter your smth: ");
    scanf("%30[^\n]", data);

    while(getchar()!='\n');

    FILE *file;
    file = fopen(data, "r");
    if (file == NULL)
    {
        printf("Couldn't open file");
        return 4;
    }

    if(checking_if_correct(file) == 0)
    {
        printf("File corrupted");
        fclose(file);
        return 6;
    }
    if(checking_if_number(file) == 0)
    {
        printf("File corrupted");
        fclose(file);
        return 6;
    }
    if (checking_if_true(file) == 0)
    {
        printf("File corrupted");
        fclose(file);
        return 6;
    }
    if(checking_size(file) == 0)
    {
        printf("File corrupted");
        fclose(file);
        return 6;
    }

    fseek(file, 0, SEEK_SET);
    do
    {
        int number;
        fscanf(file, "%i", &number);

        FILE* tested_file;
        tested_file = fopen(data, "r");
        if(!tested_file)
        {
            printf("Incorrect input");
            fclose(file);
            return 1;
        }
        fseek(tested_file, number, SEEK_SET);

        char check = fgetc(tested_file);
        fclose(tested_file);
        printf("%c", check);
    }
    while (fgetc(file) != '\n');

    fclose(file);
    return 0;
}

int checking_if_correct(FILE *file)
{
    fseek(file, 0, SEEK_SET);

    int counter = 0;
    while(fgetc(file) != EOF)
    {
        counter++;
    }

    fseek(file, 0, SEEK_SET);
    while(fgetc(file) != '\n')
    {
        fseek(file, -1, SEEK_CUR);

        int index;
        int check = fscanf(file, "%i", &index);

        if (check == 1 && index < counter)
        {
            continue;
        }

        return 0;
    }

    return 1;
}

int checking_if_number(FILE *file)
{
    fseek(file, 0, SEEK_SET);

    int number;
    while((number = fgetc(file)) != '\n')
    {
        if (isdigit(number) == 0 && number != ' ')
        {
            return 0;
        }
    }

    return 1;
}

int checking_if_true(FILE *file)
{
    fseek(file, 0, SEEK_SET);

    int index;
    int maxsize = 0;
    while(fgetc(file) != '\n')
    {
        maxsize++;
    }

    fseek(file, 0, SEEK_SET);
    while(fgetc(file) != '\n')
    {
        fseek(file, -1, SEEK_CUR);
        int check = fscanf(file, "%i", &index);
        if (check != 1 || index < maxsize)
        {
            return 0;
        }
    }

    return 1;
}

int checking_size(FILE *file)
{
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    return size;
}
