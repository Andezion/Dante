#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct helpers
{
    int number;
    char *data;
    char *check;

    int counter;
    int count;
    unsigned int numbers;
};

struct message_t
{
    char a;
    double b;
    int c;
};

int decode_message(const struct message_t *cp, int size, char *msg, int text_size);
int load_data(struct message_t *cp, int size, const char *filename);

int main()
{
    char filename[31];
    struct message_t cp[100];

    printf("Enter name: ");
    scanf("%30[^\n]", filename);
    int error = load_data(cp, 100, filename);
    if (error == -2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if (error == -3)
    {
        printf("File corrupted");
        return 6;
    }

    char message[2000];
    decode_message(cp, error, message, 2000);
    printf("%s", message);

    return 0;
}

int decode_message(const struct message_t *cp, int size, char *msg, int text_size)
{
    if (cp == NULL || msg == NULL || size <= 0 || text_size <= 0)
    {
        return 1;
    }

    for (int i = 0; i < text_size; i++)
    {
        *(msg + i) = '\0';
    }

    struct helpers hp;

    hp.number = 0;
    hp.data = NULL;
    hp.check = NULL;

    for (int i = 0; i < size; i++)
    {
        hp.data = malloc(12 * sizeof(char));
        if (hp.data == NULL)
        {
            return 1;
        }
        hp.check = (char *) (cp + i) + 1;
        for (int j = 0; j < 7; j++)
        {
            *(hp.data + j) = *(hp.check + j);
        }

        hp.check = (char *) (cp + i) + 20;
        for (int j = 0; j < 4; j++)
        {
            *(hp.data + 7 + j) = *(hp.check + j);
        }
        *(hp.data + 11) = '\0';

        for (size_t j = 0; j < strlen(hp.data); j++)
        {
            *(msg + hp.number) = *(hp.data + j);
            hp.number++;
        }

        free(hp.data);
    }

    *(msg + text_size - 1) = '\0';
    return 0;
}



int load_data(struct message_t *cp, int size, const char *filename)
{
    if (cp == NULL || filename == NULL || size <= 0)
    {
        return -1;
    }

    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        return -2;
    }

    struct helpers hp;

    hp.numbers = 0;
    hp.counter = 0;
    hp.count = 0;

    unsigned long error = fread(&hp.numbers, sizeof(int), 1, file);
    if (error != 1)
    {
        fclose(file);
        return -3;
    }

    if (hp.numbers % 24 != 0)
    {
        fclose(file);
        return -3;
    }

    for (unsigned int i = 0; i < hp.numbers / 24 && hp.count < size; i++)
    {
        error = fread((cp + hp.count), 24, 1, file);
        if (error != 1)
        {
            fclose(file);
            return -3;
        }
        hp.counter++;
        hp.count++;
    }

    fclose(file);
    return hp.counter;
}
