#include <stdio.h>

int message_compression(char* txt)
{
    if(txt == NULL)
    {
        return -1;
    }

    int counter = 0;
    int pointer = 1;

    for (int i = 0; *(txt + i) != '\0'; i++)
    {
        char to_check = *(txt + i);

        if ((to_check >= 'a' && to_check <= 'z') || (to_check >= 'A' && to_check <= 'Z'))
        {
            if (pointer == 1)
            {
                if (to_check >= 'a' && to_check <= 'z')
                {
                    *(txt + i) = to_check - ('a' - 'A');
                }
                pointer = 0;
            }
            else
            {
                if (to_check >= 'A' && to_check <= 'Z')
                {
                    *(txt + i) = to_check + ('a' - 'A');
                }
            }
        }
        else
        {
            for (int j = i; *(txt + j) != '\0'; j++)
            {
                *(txt + j) = *(txt + j + 1); // просто убираем ненужную хуйню
            }

            i--;
            counter++;
            pointer = 1;
        }
    }

    return counter;
}

int main()
{
    char txt[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",txt);

    int result = message_compression(txt);
    if (result == -1)
    {
        printf("\nNothingToShow\n");
        return 1;
    }

    int lolkek = 0;
    for(int i = 0; *(txt + i) != '\0'; i++)
    {
        if((*(txt + i) >= 'a' && *(txt + i) <= 'z') || (*(txt + i) >= 'A' && *(txt + i) <= 'Z'))
        {
            lolkek = 1;
        }
    }
    if(lolkek != 1)
    {
        printf("\nNothingToShow\n");
        return 0;
    }

    printf("\n%s\n",txt);

    return 0;
}
