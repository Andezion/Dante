#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc <= 2)
    {
        return printf("Not enough arguments"), 9;
    }

    FILE *file_to_take = fopen(*(argv + 1),"rb");
    if(file_to_take == NULL)
    {
        return printf("Couldn't open file"), 4;
    }

    FILE *file_to_put = fopen(*(argv + 2),"wb");
    if(file_to_put == NULL)
    {
        return fclose(file_to_take), printf("Couldn't create file"), 5;
    }

    for(;!feof(file_to_take);)
    {
        char letter;
        fread(&letter, sizeof(char), 1, file_to_take);

        if(feof(file_to_take))
        {
            break;
        }
        
        fwrite(&letter, sizeof(char), 1, file_to_put);
    }

    fclose(file_to_put);
    fclose(file_to_take);

    printf("File copied");
    return 0;
}
