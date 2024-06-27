#include <stdio.h>
#include <unistd.h>

int main()
{
    char name[31];

    printf("Enter name: ");
    scanf("%30[^\n]",name);

    FILE *file;
    file = fopen(name, "a+");
    if(!file)
    {
        printf("Couldn't create file");
        return 5;
    }

    while(getchar() != '\n');
    fseek(file, -1, SEEK_SET);

    int temp;
    printf("Enter text:\n");
    
    while ((temp = getchar()) != '\0' && temp != EOF)
    {
        fputc(temp, file);
    }

    fseek(file, -1, SEEK_END);
    ftruncate(fileno(file), ftell(file));

    fclose(file);

    printf("File saved");

    return 0;
}
