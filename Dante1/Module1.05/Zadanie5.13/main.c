#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Enter smth:\n");

    char data[1000];
    scanf("%999[^\n]", data);

    size_t size = strlen(data);

    char letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
    }

    int result[26] = { 0 };
    for (size_t i = 0; i < size; i++)
    {
        char to_check = tolower(data[i]);

        for (int j = 0; j < 26; j++)
        {
            if (to_check == letters[j])
            {
                result[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c: %i\n", letters[i], result[i]);
    }

    return 0;
}

