#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int cheker(char letter)
{
    if(tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'y'
       || tolower(letter) == 'u' || tolower(letter) == 'i' || tolower(letter) == 'o')
    {
        return 1;
    }
    return 0;
}

struct student_t
{
    char name[20];
    char surname[40];
    int index;
    char field[50];
    char faculty[80];
    int year;
};

struct student_t* read(struct student_t* p, int *err_code);
struct student_t* set(struct student_t* student, const char * name,
                      const char * surname, int index,
                      const char * field, const char * faculty,
                      int year, int *err_code);

void display(const struct student_t* p)
{
    if(p == NULL)
    {
        return;
    }

    if(cheker(*(p->field + 0)))
    {
        printf("%s %s, index number: %d, was an %s student at the %s in %i.\n", p->name, p->surname, p->index, p->field, p->faculty, p->year);
    }
    else
    {
        printf("%s %s, index number: %d, was a %s student at the %s in %i.\n", p->name, p->surname, p->index, p->field, p->faculty, p->year);
    }
}

void display_name(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }

    printf("Student name: %s\n",student->name);
}
void display_surname(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }
    printf("Student surname: %s\n",student->surname);
}
void display_index(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }
    printf("Index: %i\n",student->index);
}
void display_field(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }
    printf("Field: %s\n",student->field);
}
void display_faculty(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }
    printf("Faculty: %s\n",student->faculty);
}
void display_year(const struct student_t* student)
{
    if(student == NULL)
    {
        return;
    }
    printf("Year: %i\n",student->year);
}

int helper(char* word, int size);

int main()
{
    struct student_t *p, karta, karta2, *p2;
    p = &karta; p2 = &karta2;
    int error = 0, *err;
    err = &error;
    printf("Enter: ");
    set(p, "Vladislav", "Doronchenkov", 245122, "Informatyka", "WEEiA", 2022, NULL);
    if ((read(p2, err) == NULL) || (error != 0))
    {
        printf("Incorrect input\n");
        display(p);
        return error;
    }
    if(strlen(p2->surname) <= 1)
    {
        printf("Incorrect input\n");
        display(p);
        return 2;
    }
    if(strlen(p2->field) <= 1 && strlen(p2->faculty) <= 1)
    {
        printf("Incorrect input\n");
        display(p);
        return 3;
    }
    if(strlen(p2->field) <= 1)
    {
        printf("Incorrect input\n");
        display(p);
        return 4;
    }
    else
    {
        display(p2);
        display(p);
        display_name(p2);
        display_surname(p2);
        display_index(p2);
        display_field(p2);
        display_faculty(p2);
        display_year(p2);
    }

    return error;
}

struct student_t* set(struct student_t* student, const char * name,
                      const char * surname, int index,
                      const char * field, const char * faculty,
                      int year, int *err_code)
{
    if(student == NULL || name == NULL || surname == NULL || field == NULL || faculty == NULL
       || strlen(name) >= 20 || strlen(surname) >= 40 || strlen(field) >= 50 || strlen(faculty) >= 80
       || index <= 0 || year <= 0)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    char *error;

    error = strcpy(student->name, name);
    if(error == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }
    error = strcpy(student->surname, surname);
    if(error == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }
    error = strcpy(student->field, field);
    if(error == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }
    error = strcpy(student->faculty, faculty);
    if(error == NULL)
    {
        if(err_code != NULL)
        {
            *err_code = 1;
        }
        return NULL;
    }

    student->index = index;
    student->year = year;


    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return student;
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
    if (!error || p->index <= 0)
    {
        if(err_code != NULL)
        {
            *err_code = 3;
        }
        return NULL;
    }
    int helper_char;
    helper_char = getc(stdin);
    while (helper_char != ',' && helper_char != '\n')
    {
        helper_char = getc(stdin);
    }

    error = helper(p->field, 50);
    if(strlen(p->field) == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 4;
        }
        return NULL;
    }
    if(!error)
    {
        if(err_code != NULL)
        {
            *err_code = 4;
        }
        return NULL;
    }

    error = helper(p->faculty, 80);
    if(strlen(p->faculty) == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 5;
        }
        return NULL;
    }
    if(!error)
    {
        if(err_code != NULL)
        {
            *err_code = 5;
        }
        return NULL;
    }

    error = scanf("%i",&p->year);
    if(!error || p->year == 0)
    {
        if(err_code != NULL)
        {
            *err_code = 6;
        }
        return NULL;
    }

    if(err_code != NULL)
    {
        *err_code = 0;
    }
    return p;
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
