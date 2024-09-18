#include <stdio.h>
#include <string.h>
#include <ctype.h>

int helper(char *word)
{
    int counter = 0;

    while (*word)
    {
        char letter = tolower(*word);
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y')
        {
            counter++;
        }
        word++;
    }

    return counter;
}

int main()
{
    printf("Enter: ");

    char data[1001];
    scanf("%1000[^\n]", data);

    size_t size = strlen(data);
    int point = 0;
    for(size_t i = 0; i < size; i++)
    {
        if(data[i] == ' ')
        {
            point = 1;
            break;
        }
    }
    if(point == 0)
    {
        int result1 = helper(data);
        printf("\n%i - %i\n",result1,1);
        return 0;
    }

    char *new_data = strtok(data, " ");

    int vector[8] = { 0 };
    int index = 0;
    int new_counter = 0;

    while (new_data != NULL)
    {
        int result = helper(new_data);

        if(result == 0)
        {
            new_counter++;
        }

        if (result > 0 && result <= 6)
        {
            vector[result]++;
        }

        new_data = strtok(NULL, " ");

        index++;
    }

    printf("\n");

    if(new_counter != 0)
    {
        printf("%i - %i\n",0,new_counter);
    }
    for (int i = 1; i <= 6; i++)
    {
        if (vector[i] > 0)
        {
            printf("%d - %d\n", i, vector[i]);
        }
    }


    return 0;
}
