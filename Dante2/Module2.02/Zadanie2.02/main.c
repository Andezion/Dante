#include <stdio.h>
#include <string.h>

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(struct student_t* p, int *err_code);
void show(const struct student_t* p);
int helper(char* word, int size);

int main()
{
    struct student_t please_work_i_beg_you;
    int kill_me;

    printf("Enter: ");
    if(read(&please_work_i_beg_you, &kill_me) == NULL)
    {
        printf("Incorrect input");
        return kill_me;
    }

    show(&please_work_i_beg_you);
    return kill_me;
}

struct student_t* read(struct student_t* p, int *err_code)
{
    if (p == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    memset(p, 0, sizeof(struct student_t));
    int error;

    error = helper(p->name, 20);
    if (!error)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    error = helper(p->surname, 40);
    if (!error)
    {
        if(err_code != NULL)
        {
            *err_code = 2;
        }
        return NULL;
    }

    error = scanf("%i", &p->index);
    if (!error)
    {
        if(err_code != NULL)
        {
            *err_code = 3;
        }
        return NULL;
    }

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return p;

}

void show(const struct student_t* p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%s %s, %d", p->name, p->surname, p->index);
}

int helper(char* word, int size)
{
    int j;
    int i = 0;
    int result = 0;
    int pointer = 0;

    while ((j = getc(stdin)) != '\n' && j != -1 && i <= size)
    {
        if (j == ',')
        {
            result = 1;
            break;
        }
        else if (j == ' ' && !pointer)
        {
            continue;
        }
        *(word + i) = (char)j;
        i++;
        pointer = 1;
    }

    *(word + i) = '\0';
    return result;
}
