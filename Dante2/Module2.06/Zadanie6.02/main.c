#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_t
{
    char *ok;
    char *name;
    char *surname;
    int index;
};

struct student_t *read(int *err_code);
void destroy(struct student_t **p);
void show(const struct student_t *p);

int main()
{
    int err_code;

    struct student_t *p = read(&err_code);
    if(err_code == 4)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    if(err_code == 3)
    {
        printf("Incorrect input");
    }
    else
    {
        show(p);
    }

    destroy(&p);
    return err_code;
}

struct student_t *read(int *err_code)
{
    struct student_t *student_data = malloc(sizeof(struct student_t));
    if (student_data == NULL)
    {
        if (err_code != NULL)
        {
            *err_code = 4;
        }
        return NULL;
    }

    char *holder = malloc(101);
    if (holder == NULL)
    {
        if (err_code != NULL)
        {
            *err_code = 4;
        }

        free(student_data);

        return NULL;
    }

    memset(student_data, 0, sizeof(struct student_t));
    printf("Enter data: ");
    scanf("%100[^\n]", holder);
    char *buf = holder;

    int error = sscanf(holder, "%[^,],%[^,],%d", student_data->name, student_data->surname, &student_data->index);
    if (error != 3)
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }

        free(student_data);
        free(buf);

        return NULL;
    }

    if (err_code != NULL)
    {
        *err_code = 0;
    }
    
    student_data->ok = buf;
    return student_data;
}

void show(const struct student_t *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%s %s, %d", p->name, p->surname, p->index);
}

void destroy(struct student_t **p)
{
    if (p == NULL || *p == NULL)
    {
        return;
    }

    if ((*p)->ok != NULL)
    {
        free((*p)->ok);
    }

    free(*p);
    *p = NULL;
}
