#include <stdio.h>

struct entry_t
{
    char name[20];
    char last_name[40];
    int number;
};

void display(const struct entry_t* p);
int load_phonebook_t(const char *filename, struct entry_t* p, int size);
const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char *last_name);

int main()
{

    return 0;
}

void display(const struct entry_t* p)
{
    if(p == NULL)
    {
        return;
    }

    printf("Name: %s\nLast name: %s\nPhone number: %i",p->name,p->last_name,p->number);
}

int load_phonebook_t(const char *filename, struct entry_t* p, int size)
{
    if(filename == NULL || p == NULL || size <= 0)
    {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        return -2;
    }

    int counter = 0;

    while(feof(file))
    {
        fscanf(file, "%[^|]19s %[^|]39s %d",(p + counter)->name, (p + counter)->last_name, &(p + counter)->number);
        /*if(error != 3)
        {
            return 0;
        }*/
        counter++;
    }

    fclose(file);
    return counter;
}

const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char *last_name)
{
    if(p == NULL || size <= 0 || last_name == NULL)
    {
        return NULL;
    }
    return p;
}
