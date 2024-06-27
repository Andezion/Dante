#include <stdio.h>

int main()
{
    FILE *file;
    char filename[31];

    printf("Enter: ");

    scanf("%30[^\n]",filename);
    file = fopen(filename, "wb");
    if(!file)
    {
        printf("Couldn't create file");
        return 5;
    }

    while(getchar() != '\n');

    fseek(file, 0, SEEK_END);

    for(int i = 0; i < 101; i++)
    {
        fprintf(file, "%i\n",i);
    }

    printf("File saved");
    fclose(file);

    return 0;
}
