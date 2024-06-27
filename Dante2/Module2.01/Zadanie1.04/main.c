#include <stdio.h>
#include <string.h>

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

    fseek(first_file, 0, SEEK_END);
    int size = ftell(first_file);
    for(int i = size - 1; i >= 0; i--)
    {
        fseek(first_file, i, SEEK_SET);
        int temp = fgetc(first_file);
        fputc(temp, second_file);
    }

    printf("File copied");
    fclose(first_file);
    fclose(second_file);

    return 0;
}
