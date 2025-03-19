#include <stdio.h>

union bit_set
{
    unsigned char letter;

    struct array
    {
        unsigned char x1: 1;
        unsigned char x2: 1;
        unsigned char x3: 1;
        unsigned char x4: 1;
        unsigned char x5: 1;
        unsigned char x6: 1;
        unsigned char x7: 1;
        unsigned char x8: 1;
    } array;
};

char helper(unsigned char letter)
{
    if(letter == 1)
    {
        return '#';
    }
    else
    {
        return ' ';
    }
}

int main()
{
    int error;
    int j = 0;
    char data[328];
    union bit_set bites;

    printf("Enter text: ");
    for(int i = 0; i < 40; i++)
    {
        error = scanf("%hhx",&(bites.letter));
        if(error != 1)
        {
            printf("Incorrect input");
            return 1;
        }

        *(data + j + 0)= helper(bites.array.x8);
        *(data + j + 1)= helper(bites.array.x7);
        *(data + j + 2)= helper(bites.array.x6);
        *(data + j + 3)= helper(bites.array.x5);
        *(data + j + 4)= helper(bites.array.x4);
        *(data + j + 5)= helper(bites.array.x3);
        *(data + j + 6)= helper(bites.array.x2);
        *(data + j + 7)= helper(bites.array.x1);

        if ((i + 1) % 5 != 0)
        {
            j = j + 8;
        }
        else
        {
            *(data + j + 8) = '\n';
            j = j + 9;
        }
    }

    while(getchar() != '\n');

    char filename[51];
    printf("Enter filename: ");
    scanf("%51[^\n]", filename);

    while(getchar() != '\n');

    for(int i = 0; i < 328; i++)
    {
        printf("%c",*(data + i));
    }

    FILE *file = fopen(filename,"wb");
    if(file == NULL)
    {
        printf("Couldn't create file");
        return 5;
    }

    fwrite(data, sizeof(char), sizeof(data), file);
    char buffer[328];
    fseek(file,0,SEEK_SET);
    fread(buffer, sizeof(char), sizeof(data), file);
    printf("File saved");

    fclose(file);
    return 0;
}
