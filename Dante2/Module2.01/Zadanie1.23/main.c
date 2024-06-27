#include <stdio.h>
#include <string.h>

int my_strcspn(const char *str, const char *reject)
{
    int i = 0;

    while (*(str + i) != '\0')
    {
        if (strchr(reject, *(str + i)) != NULL)
        {
            break;
        }
        i++;
    }

    return i;
}

int read_file(const char *filename)
{
    if (filename == NULL)
    {
        return -1;
    }

    FILE *file;
    file = fopen(filename, "r");
    if (!file)
    {
        return 0;
    }

    char storage[31];
    int returning = 1;

    while (fgets(storage, sizeof(storage), file) != NULL)
    {
        *(storage + my_strcspn(storage, "\n")) = '\0';
        printf("%s\n", storage);

        if (strlen(storage) < 31)
        {
            int number = read_file(storage);
            if (number > 0)
            {
                returning = returning + number;
            }
        }
    }

    fclose(file);
    return returning;
}

int main()
{
    char filename[31];
    printf("Enter: ");
    scanf("%30[^\n]", filename);

    int number = read_file(filename);
    if (number <= 0)
    {
        printf("Couldn't open file");
        return 4;
    }

    printf("%i", number);
    return 0;
}

