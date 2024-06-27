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
    int more = 0;
    int popa = 0;
    while((error = fgetc(file1)) != EOF)
    {
        if(isdigit(error))
        {
            popa = 1;
        }
        if(isalpha(error))
        {
            more = 1;
        }
    }
    if(popa == 0 || more == 1)
    {
        printf("File corrupted");
        fclose(file1);
        return 6;
    }
    fseek(file1, 0, SEEK_SET);

    int n;
    error = fscanf(file1, "%i", &n);
    if(error != 1 || n <= 0)
    {
        printf("File corrupted");

        fclose(file1);

        return 6;
    }

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
    int count = 0;
    int num;

    while (fscanf(file1, "%d", &num) == 1)
    {
        if (num > 0)
        {
            sum = sum + num;
            count++;
        }

        if (count == n)
        {
            break;
        }
    }

    if (count < n)
    {
        fprintf(file2, "-1\n");
    }
    else
    {
        fprintf(file2, "%i\n", sum);
    }

    fclose(file1);
    fclose(file2);

    printf("File saved");
    return 0;
}
