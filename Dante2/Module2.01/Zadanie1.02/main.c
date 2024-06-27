#include <stdio.h>


int file_size_from_path(const char *path)
{
    if(path == NULL)
    {
        return -2;
    }
    FILE *file = fopen(path,"r");
    if(!file)
    {
        return -1;
    }

    fseek(file, 0, SEEK_END);

    int size = ftell(file);
    fclose(file);
    return size;
}

int file_size_from_file(FILE *f)
{
    if(f == NULL)
    {
        return -2;
    }

    int look = ftell(f);
    if(look == -1)
    {
        return -1;
    }

    fseek(f, 0, SEEK_END); //переходим в конец, чтобы размер посмотреть

    int temp = ftell(f);
    if(temp == -1)
    {
        return temp;
    }

    fseek(f, look, SEEK_SET);
    return temp;
}

int main()
{
    FILE *file;
    char name[31];

    printf("Enter: ");
    scanf("%30[^\n]",name);

    int first = file_size_from_path(name);
    if(first < 0)
    {
        printf("Couldn't open file");
        return 4;
    }

    file = fopen(name,"rb");
    if(!file)
    {
        printf("Couldn't open file");
        return 4;
    }

    int second = file_size_from_file(file);
    fclose(file);
    if(second == -2)
    {
        printf("Error");
        return 0;
    }
    if(second == -1)
    {
        printf("Couldn't open file");
        return 4;
    }

    if(first != second)
    {
        printf("Error");
        return 0;
    }

    printf("Result: %i\n",first);
    return 0;
}
