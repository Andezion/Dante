#include <stdio.h>
#include <ctype.h>

int main()
{
    char file_in[31];
    printf("Enter input: ");
    scanf("%30[^\n]", file_in);
    while (getchar() != '\n');

    FILE *file1;
    file1 = fopen(file_in, "r");
    if (!file1)
    {
        printf("Couldn't open file");
        return 4;
    }

    fseek(file1, 0, SEEK_END);
    int size = ftell(file1);
    if(size == 0)
    {
        printf("File corrupted");
        fclose(file1);
        return 6;
    }
    fseek(file1, 0, SEEK_SET);

    int error;
    int popa = 0;
    while((error = fgetc(file1)) != EOF)
    {
        if(isdigit(error))
        {
            popa = 1;
        }
    }
    if(popa == 0)
    {
        printf("File corrupted");
        fclose(file1);
        return 6;
    }
    fseek(file1, 0, SEEK_SET);

    char file_out[31];
    printf("Enter output: ");
    scanf("%30[^\n]", file_out);
    while (getchar() != '\n');

    FILE *file2;
    file2 = fopen(file_out, "w");
    if (!file2)
    {
        printf("Couldn't create file");
        fclose(file1);
        return 5;
    }

    int sum = 0;
    int num_started = 0;
    int num = 0;
    int is_negative = 0;

    int ch;
    int counter = 0;
    int temp = 0;

    while (1)
    {
        ch = fgetc(file1);
        counter++;
        if (isdigit(ch) || ch == '-')
        {
            if (!num_started)
            {
                num_started = 1;
                num = 0;
                if (ch == '-')
                {
                    is_negative = 1;
                }
                else
                {
                    is_negative = 0;
                }
            }

            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
                temp++;
            }
        }
        else
        {
            if (num_started)
            {
                if (is_negative)
                {
                    sum += -num;
                }
                else
                {
                    sum += num;
                }
                num_started = 0;
            }

            if (ch == '\n')
            {
                if (counter == 1)
                {
                    counter = 0;
                    temp = 0;
                    continue;
                }
                if(sum == 0 && temp == 0)
                {
                    continue;
                }
                counter = 0;
                fprintf(file2, "%d\n", sum);
                temp = 0;
                sum = 0;
            }
            if (ch == EOF)
            {
                if (counter == 1 || sum == 0)
                {
                    break;
                }
                fprintf(file2, "%i\n", sum);
                break;
            }

            is_negative = 0;
        }
    }

    fclose(file1);
    fclose(file2);

    printf("File saved");
    return 0;
}

