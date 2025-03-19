#include <stdio.h>
#include <string.h>
#include <ctype.h>

union setter
{
    unsigned char byte;
    struct dupa
    {
        unsigned x1: 1;
        unsigned x2: 1;
        unsigned x3: 1;
        unsigned x4: 1;
        unsigned x5: 1;
        unsigned x6: 1;
        unsigned x7: 1;
        unsigned x8: 1;
    } getter;
};

int decode(const char *filename, char *txt, int size);
int encode(const char *input, char *txt, const char *output);

int main()
{
    char from_this_data[30];
    char to_this_data[30];

    char password[1001];
    char our_data[1001];

    char dupochka;

    printf("What to do: ");
    scanf("%c", &dupochka);

    while(getchar() != '\n');

    if(tolower(dupochka) == 'd')
    {
        printf("Enter input file name:");
        scanf("%29[^\n]", from_this_data);

        while(getchar() != '\n');

        int resulted = decode(from_this_data, password, 1001);
        if(resulted == 0)
        {
            int i = 0;
            while(i < 1000 && *(password + i) != '\0')
            {
                if(*(password + i) < 32 || isdigit(*(password + i)))
                {
                    printf("File corrupted");
                    return 6;
                }
                i++;
            }
            printf("%s", password);
        }
        if(resulted == 2)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(resulted == 3)
        {
            printf("File corrupted");
            return 6;
        }
    }

    else if(tolower(dupochka) == 'e')
    {
        printf("Enter: ");
        scanf("%1000[^\n]", our_data);

        while(getchar() != '\n');

        printf("Enter: ");
        scanf("%29[^\n]", from_this_data);

        while(getchar() != '\n');

        printf("Enter: ");
        scanf("%29[^\n]", to_this_data);

        while(getchar() != '\n');

        int errorchik = encode(from_this_data, our_data, to_this_data);
        if(errorchik == 3)
        {
            printf("File corrupted");
            return 6;
        }
        if(errorchik == 4)
        {
            printf("Couldn't create file");
            return 5;
        }
        if(errorchik == 2)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(errorchik == 0)
        {
            printf("File saved");
            return 0;
        }
    }

    else
    {
        printf("Incorrect input data");
        return 1;
    }

    return 0;
}

int decode(const char *filename, char *txt, int size)
{
    if(txt == NULL || size < 1 || filename == NULL)
    {
        return 1;
    }

    FILE *f;
    f = fopen(filename, "r");
    if(!f)
    {
        return 2;
    }

    union setter type_one;
    union setter type_two;

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    for(;!feof(f);)
    {
        fscanf(f, "%s", &type_two.byte); num3++;
    }

    if(num3 == (size + 1))
    {
        return fclose(f), 3;
    }

    long int file_size = ftell(f);
    rewind(f);

    int error;
    for (;!feof(f);)
    {
        error = fscanf(f, "%hhu", &type_two.byte);
        if (error != 1)
        {
            if (ftell(f) >= file_size)
            {
                return fclose(f), 0;
            }
            else
            {
                return fclose(f), 3;
            }
        }


        switch (num1)
        {
            case 0:
                type_one.getter.x8 = type_two.getter.x1;
                break;
            case 1:
                type_one.getter.x7 = type_two.getter.x1;
                break;
            case 2:
                type_one.getter.x6 = type_two.getter.x1;
                break;
            case 3:
                type_one.getter.x5 = type_two.getter.x1;
                break;
            case 4:
                type_one.getter.x4 = type_two.getter.x1;
                break;
            case 5:
                type_one.getter.x3 = type_two.getter.x1;
                break;
            case 6:
                type_one.getter.x2 = type_two.getter.x1;
                break;
            case 7:
                type_one.getter.x1 = type_two.getter.x1;
                *(txt + num2) = (char) type_one.byte;
                num1 = -1;
                num2++;

                if(num2 == size - 1)
                {
                    return *(txt + num2) = '\0', fclose(f), 0;
                }

                break;
        }

        num1++;
    }

    fclose(f);
    return 0;
}

int encode(const char *input, char *txt, const char *output)
{
    if(txt == NULL || output == NULL || input == NULL)
    {
        return 1;
    }

    FILE *what_to_read = fopen(input, "r");
    if(what_to_read == NULL)
    {
        return 2;
    }

    FILE *what_to_write = fopen(output, "w");
    if(what_to_write == NULL)
    {
        return fclose(what_to_read), 4;
    }

    int counter = 0;
    int number = 0;
    int int_used = 0;
    int char_used = 0;

    size_t some_shit = 0;
    int char_shit = (int) strlen(txt);

    union setter bilder;
    union setter dibilder;

    char letter;
    char *temporary;

    for(;!feof(what_to_read);)
    {
        fscanf(what_to_read, "%s", &dibilder.byte);
        some_shit++;
    }
    some_shit--;

    if(some_shit < strlen(txt))
    {
        return fclose(what_to_read), fclose(what_to_write), 3;
    }

    rewind(what_to_read);

    for(;!feof(what_to_read);)
    {
        fscanf(what_to_read, "%c", &letter);
        if(isalpha(letter))
        {
            return fclose(what_to_read), fclose(what_to_write), 3;
        }
    }

    rewind(what_to_read);

    letter = 0;

    for(;letter != '\n';)
    {
        fscanf(what_to_read, "%c", &letter);
        if(letter == ' ')
        {
            number++;
        }
    }

    rewind(what_to_read);

    temporary = txt;

    int errorchik;
    while(txt != NULL && !feof(what_to_read))
    {
        errorchik = fscanf(what_to_read, "%hhu", &dibilder.byte);
        if (errorchik != 1)
        {
            return fclose(what_to_read), fclose(what_to_write), 0;
        }

        switch (counter)
        {
            case 0:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    bilder.byte = *temporary;
                    dibilder.getter.x1 = bilder.getter.x8;
                }
                break;
            case 1:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x7;
                }
                break;
            case 2:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x6;
                }
                break;
            case 3:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x5;
                }
                break;
            case 4:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x4;
                }
                break;
            case 5:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x3;
                }
                break;
            case 6:
                if (char_used == char_shit)
                {
                    dibilder.getter.x1 = 0;
                }
                else
                {
                    dibilder.getter.x1 = bilder.getter.x2;
                }
                break;
            case 7:
                if(char_used != char_shit)
                {
                    char_used++;
                    dibilder.getter.x1 = bilder.getter.x1;
                }
                else
                {
                    dibilder.getter.x1 = 0;
                }
                counter = -1;
                temporary++;
                break;
        }

        if(int_used % number == 0 && int_used != 0)
        {
            fprintf(what_to_write, "\n%hhu", dibilder.byte);
        }
        else if(int_used % number != 0)
        {
            fprintf(what_to_write, " %hhu", dibilder.byte);
        }
        else
        {
            fprintf(what_to_write, "%hhu", dibilder.byte);
        }

        int_used++;
        counter++;
    }

    fclose(what_to_read);
    fclose(what_to_write);

    return 0;
}
