#include <stdio.h>

int main()
{
    FILE *first_file;
    char filename1[31];
    printf("Enter: ");

    scanf("%30[^\n]",filename1);
    first_file = fopen(filename1, "rb");
    if(!first_file)
    {
        printf("Couldn't open file");
        return 4;
    }

    while(getchar() != '\n');

    FILE *second_file;
    char filename2[31];
    printf("Enter: ");

    scanf("%30[^\n]",filename2);
    second_file = fopen(filename2, "wb");
    if(!second_file)
    {
        printf("Couldn't create file");
        fclose(first_file);
        return 5;
    }

    char text[31];
    size_t pointer;

    while(0 < (pointer = fread(text, sizeof(char), sizeof(text), first_file)))
    {
        fwrite(text, sizeof(char), pointer, second_file);
    }

    printf("File copied");
    fclose(first_file);
    fclose(second_file);


    return 0;
}
