#include <stdio.h>

int my_strlen(const char* str)
{
    if (str == NULL)
    {
        return -1;
    }
    int size = 0;
    while (*(str + size) != '\0')
    {
        size++;
    }
    return size;
}

char* my_strcpy(char* dest, const char* src)
{
    if (src == NULL || dest == NULL)
    {
        return NULL;
    }

    size_t i;

    for (i = 0; *(src + i) != '\0'; i++)
    {
        *(dest + i) = *(src + i);
    }
    *(dest + i) = '\0';

    return dest;
}

char* my_strcat(char* dest, const char* src)
{
    if (src == NULL || dest == NULL)
    {
        return NULL;
    }

    int i = 0;
    int size = my_strlen(dest);

    while (*(src + i) != '\0')
    {
        *(dest + size + i) = *(src + i);
        i++;
    }
    *(dest + size + i) = '\0';

    return dest;
}

int main()
{
    char txt1[1001];
    char txt2[1001];
    char result[2003];

    printf("Enter: ");
    scanf("%1000[^\n]", txt1);

    while(getchar() != '\n');

    printf("\nEnter: ");
    scanf("%1000[^\n]", txt2);

    while(getchar() != '\n');

    printf("\n%i %i\n", my_strlen(txt1), my_strlen(txt2));

    my_strcat(result, txt2);
    my_strcat(result, txt1);
    printf("%s\n", result);


    my_strcpy(result, txt1);
    printf("%s\n", result);
    return 0;
}
