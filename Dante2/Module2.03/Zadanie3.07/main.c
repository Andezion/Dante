#include <stdio.h>

union double_to_char_t
{
    double d;
    char tab[8];
};

int save_double(const union double_to_char_t *dtc, const char *filename);
int load_double(union double_to_char_t *dtc, const char *filename);

int main()
{
    int error;
    union double_to_char_t p;

    double number;
    printf("Enter: ");

    error = scanf("%lf", &number);
    if(!error)
    {
        printf("Incorrect input");
        return 1;
    }
    p.d = number;

    while (getchar() != '\n');
    char file_one[40];

    printf("Enter: ");
    scanf("%39[^\n]", file_one);

    error = save_double(&p, file_one);
    if(error == 1)
    {
        printf("Kill me plz");
        return 1;
    }
    if(error == 2)
    {
        printf("Couldn't create file");
        return 5;
    }
    if(error == 3)
    {
        printf("File corrupted");
        return 6;
    }

    printf("File saved\n");

    while (getchar () != '\n' );

    char file_two[40];
    printf("Enter: ");
    scanf("%39[^\n]", file_two);

    error = load_double(&p, file_two);
    if(error == 1)
    {
        printf("Kill me plz");
        return 1;
    }
    if(error == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(error == 3)
    {
        printf("File corrupted");
        return 6;
    }

    printf("%lf",p.d);
    return 0;
}

int save_double(const union double_to_char_t *dtc, const char *filename)
{
    if(dtc == NULL || filename == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "wb");
    if(!file)
    {
        return 2;
    }

    size_t error = fwrite(dtc->tab, sizeof(union double_to_char_t), 1, file);

    fclose(file);
    if(error != 1)
    {
        return 3;
    }
    return 0;
}

int load_double(union double_to_char_t *dtc, const char *filename)
{
    if(dtc == NULL || filename == NULL)
    {
        return 1;
    }

    FILE *file;
    file = fopen(filename, "rb");
    if(file == NULL)
    {
        return 2;
    }

    size_t error = fread(dtc->tab, sizeof(union double_to_char_t), 1, file);

    fclose(file);
    if(error != 1)
    {
        return 3;
    }
    return 0;
}
