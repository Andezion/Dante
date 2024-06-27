#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Enter: ");

    int number;
    int check = scanf("%i",&number);
    if(!check)
    {
        printf("Incorrect input");
        return 1;
    }
    if(0 >= number || number > 1000)
    {
        printf("Incorrect input data");
        return 2;
    }

    FILE *file;
    char name[10];

    int counter = 0;
    while(counter != number)
    {
        if(counter % 10 == 0)
        {
            snprintf(name, 10, "%i.txt",counter / 10);
            file = fopen(name,"wb");
            if(!file)
            {
                printf("Couldn't create file");
                return 5;
            }
        }

        int temp = rand() % 1001;
        fprintf(file, "%i\n",temp);

        if(counter % 10 == 9)
        {
            fclose(file);
            printf("%s\n",name);
        }

        counter++;
    }

    if(counter % 10 != 0)
    {
        printf("%s\n",name);
    }

    if(number == 1000)
    {
        
    }
    else
    {
        fclose(file);
    }
    return 0;
}
