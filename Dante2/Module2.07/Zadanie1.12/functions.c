#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void print_rabbit(void)
{
    printf(" \\\\   //\n");
    printf("  )\\-/(\n");
    printf("  /o o\\\n");
    printf(" ( =T= )\n");
    printf(" /'---'\\\n");
}

void print_egg(void)
{
    printf("  .~~~.\n");
    printf(" /     \\\n");
    printf("(\\/\\/\\/\\)\n");
    printf(" \\     /\n");
    printf("  `~~~`\n");
}

void print_chicken(void)
{
    printf(" MM\n");
    printf("<' \\___/|\n");
    printf("  \\_  _/\n");
    printf("    ][\n");
}

void *easter(int size, void (*var1) (void), void (*var2) (void), void (*var3) (void))
{
    if(var1 == NULL || var2 == NULL || var3 == NULL || size <= 0)
    {
        return NULL;
    }

    srand(time(NULL));

    void(**popka)(void);
    popka = malloc(size * sizeof(void (*)(void)));
    if(popka == NULL)
    {
        return NULL;
    }

    int dupko;
    for(int i = 0; i < size; i++)
    {
        dupko = rand() % 3;
        if(dupko == 0)
        {
            *(popka + i) = var1;
        }
        else if(dupko == 1)
        {
            *(popka + i) = var2;
        }
        else
        {
            *(popka + i) = var3;
        }
    }

    return popka;
}
