#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    char name[31];
    srand(time(NULL));

    printf("Enter: ");
    scanf("%30[^\n]",name);

    file = fopen(name,"wb");
    if(!file)
    {
        printf("Couldn't create file");
        return 5;
    }

    while(getchar() != '\n');

    for (int i = 0; i < 100; i++)
    {
        int num1 = -100 + rand() % 201;
        int num2 = -10 + rand() % 20;

        float temp;
        if (num2 != 0)
        {
            temp = (float) num1 / (float) num2;
        }
        else
        {
            temp = 0;
        }
        fwrite(&temp, sizeof(float), 1, file);
    }

    printf("File saved");
    fclose(file);
    return 0;
}

