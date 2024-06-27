#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_0, *file_2, *file_3, *file_5;

    file_0 = fopen("0.txt","w");
    if(!file_0)
    {
        printf("Couldn't create file");
        return 5;
    }

    file_2 = fopen("2.txt","w");
    if(!file_2)
    {
        printf("Couldn't create file");
        fclose(file_0);
        return 5;
    }

    file_3 = fopen("3.txt","w");
    if(!file_3)
    {
        printf("Couldn't create file");
        fclose(file_0);
        fclose(file_2);
        return 5;
    }

    file_5 = fopen("5.txt","w");
    if(!file_5)
    {
        printf("Couldn't create file");
        fclose(file_0);
        fclose(file_2);
        fclose(file_3);
        return 5;
    }

    fseek(file_0, 0, SEEK_END);
    fseek(file_2, 0, SEEK_END);
    fseek(file_3, 0, SEEK_END);
    fseek(file_5, 0, SEEK_END);

    int number = 1;
    printf("Enter: ");
    while(number != 0)
    {
        int check = scanf("%i",&number);
        if(!check)
        {
            printf("Error!");
            return 1;
        }

        if(number == 0)
        {
            break;
        }

        int temp = abs(number);

        if (temp % 2 == 0)
        {
            fprintf(file_2, "%i\n", number);
        }
        if (temp % 3 == 0)
        {
            fprintf(file_3, "%i\n", number);
        }
        if (temp % 5 == 0)
        {
            fprintf(file_5, "%i\n", number);
        }
        if(temp % 2 != 0 && temp % 3 != 0 && temp % 5 != 0)
        {
            fprintf(file_0, "%i\n", number);
        }
    }

    printf("Files saved");

    fclose(file_0);
    fclose(file_2);
    fclose(file_3);
    fclose(file_5);

    return 0;
}
