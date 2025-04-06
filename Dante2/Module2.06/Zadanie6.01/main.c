#include <stdio.h>
#include <stdlib.h>

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t *read(int *err_code)
{
    struct student_t *dupko = malloc(sizeof(struct student_t));
    if (dupko == NULL)
    {
        if (err_code)
        {
            *err_code = 4;
        }

        printf("Failed to allocate memory");
        return NULL;
    }

    int error;

    char space;
    int pointer_for_name = 0;

    printf("Enter: ");
    for (int i = 0; i < 20; i++)
    {
        error = scanf("%c", dupko->name + i);

        if (*(dupko->name + i) == ',')
        {
            pointer_for_name = 1;
            *(dupko->name + i) = '\0';
            break;
        }
        if (error != 1 || *(dupko->name + i) == '\n')
        {
            if (err_code != NULL)
            {
                *err_code = 1;
            }

            free(dupko);
            return NULL;
        }
    }

    if (pointer_for_name == 0)
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }

        free(dupko);
        return NULL;
    }

    error = scanf("%c", &space);
    if (error != 1 && space != ' ')
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }

        free(dupko);
        return NULL;
    }

    int pointer_for_surname = 0;

    for (int i = 0; i < 40; i++)
    {
        error = scanf("%c", dupko->surname + i);
        if (*(dupko->surname + i) == ',')
        {
            pointer_for_surname = 1;
            *(dupko->surname + i) = '\0';
            break;
        }
        if (error != 1 || *(dupko->surname + i) == '\n')
        {
            if (err_code != NULL)
            {
                *err_code = 2;
            }

            free(dupko);
            return NULL;
        }
    }

    if (pointer_for_surname == 0)
    {
        if (err_code != NULL)
        {
            *err_code = 2;
        }

        free(dupko);
        return NULL;
    }

    error = scanf("%c", &space);
    if (error != 1 && space != ' ')
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }

        free(dupko);
        return NULL;
    }

    error = scanf("%d", &dupko->index);
    if (error != 1)
    {
        if (err_code != NULL)
        {
            *err_code = 3;
        }

        free(dupko);
        return NULL;
    }

    if (err_code != NULL)
    {
        *err_code = 0;
    }
    return dupko;
}

void destroy(struct student_t **s);
void show(const struct student_t *p);

int main()
{
    int errorchik;
    struct student_t *i_hate_myself;
    i_hate_myself = read(&errorchik);

    if (!!errorchik && errorchik < 4)
    {
        printf("Incorrect input");
        return errorchik;
    }
    if (errorchik == 4)
    {
        return 8;
    }

    show(i_hate_myself);
    destroy(&i_hate_myself);

    return 0;
}

void destroy(struct student_t **s)
{
    if (s == NULL || *s == NULL)
    {
        return;
    }
    
    free(*s);
}

void show(const struct student_t *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%s %s, %d", p->name, p->surname, p->index);
}
