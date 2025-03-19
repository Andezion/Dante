#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct file_t
{
    FILE *f;
    int size;
};

int open_file(struct file_t* f, const char *filename);
struct file_t* find_min(const struct file_t* files, int size);
void close_file(struct file_t* f);

int main()
{
    char filenames[1000];
    struct file_t files[5];

    int counter = 0;
    int helper_for_counter = 0;

    printf("Enter:\n");
    while (counter < 5)
    {
        fgets(filenames, 999, stdin);
        if (strlen(filenames) == 1)
        {
            break;
        }

        *(filenames + strcspn(filenames, "\n")) = '\0';

        int status = open_file(files + counter, filenames);
        if (status != 0)
        {
            counter--;
            helper_for_counter++;
        }

        if (helper_for_counter >= 5)
        {
            printf("Couldn't open file");
            return 4;
        }
        counter++;
    }

    if (counter == 0)
    {
        printf("Couldn't open file");
        return 4;
    }
    if (counter == 5)
    {
        while(getchar() != '\n');
    }

    size_t size;
    char text[1000];

    printf("Enter:\n");
    while (fgets(text, 999, stdin) != NULL)
    {
        size = strlen(text);
        if (size == 1)
        {
            break;
        }

        struct file_t *tester = find_min(files, counter);
        if(tester == NULL)
        {
            printf("Incorrect input");
            return 1;
        }
        
        fwrite(text, sizeof(char), size, tester->f);
        fflush(tester->f);
        tester->size = ftell(tester->f);
    }


    for (int i = 0; i < counter; i++)
    {
        close_file(files + i);
    }
    return 0;
}

struct file_t* find_min(const struct file_t* files, int size)
{
    if(files == NULL || size <= 0)
    {
        return NULL;
    }

    const struct file_t *temp1;
    const struct file_t *temp2;

    temp1 = (files + 0);
    for(int i = 1; i < size; i++)
    {
        temp2 = (files + i);
        if(temp1->size > temp2->size)
        {
            temp1 = temp2;
        }
    }

    return (struct file_t *)temp1;
}

void close_file(struct file_t* f)
{
    if(f != NULL)
    {
        if(f->f != NULL)
        {
            fclose(f->f);
            f->f = NULL;
            f->size = 0;
        }
    }
}

int open_file(struct file_t* f, const char *filename)
{
    if(f == NULL || filename == NULL)
    {
        return 1;
    }

    f->f = fopen(filename, "a+");
    if(!f->f)
    {
        return 2;
    }

    fseek(f->f, 0, SEEK_END);
    f->size = ftell(f->f);

    return 0;
}
