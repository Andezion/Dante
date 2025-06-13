#include <stdio.h>

char *my_strpbrk(const char *where, const char *from)
{
    while (*where != '\0')
    {
        const char *temp = from;
        while (*temp != '\0')
        {
            if (*where != *temp)
            {
                temp++;
            }
            else
            {
                return (char *) where;
            }
        }
        where++;
    }
    return NULL;
}

int helper(const char *text)
{
    int count = 0;
    const char *vector = "aeiyouAEIYOU";

    while (*text != '\0')
    {
        char *what = my_strpbrk(text, vector);
        if (what == NULL)
        {
            break;
        }
        else
        {
            count++;
            text = what + 1;
        }
    }

    return count;
}

int main()
{
    char text[1001];

    printf("Enter: ");
    scanf("%1000[^\n]",text);

    int result = helper(text);
    printf("\n%i\n", result);

    return 0;
}
