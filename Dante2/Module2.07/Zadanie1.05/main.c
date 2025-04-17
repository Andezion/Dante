#include <stdio.h>
#include <malloc.h>
#include "char_operations.h"
typedef char operations(char);

int main()
{
    int error;

    operations *funks[4] = {lower_to_upper, upper_to_lower, space_to_dash, reverse_letter};

    char *work = malloc(sizeof(char) * 1001);
    if(work == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter your data: ");
    scanf("%1000[^\n]",work);

    while(getchar() != '\n');

    int your_pick;
    printf("Enter your_pick: ");
    error = scanf("%i", &your_pick);
    if(error != 1)
    {
        printf("Incorrect input");

        free(work);

        return 1;
    }
    if(your_pick < 0 || your_pick > 3)
    {
        printf("Incorrect input data");

        free(work);

        return 2;
    }

    char *result = letter_modifier(work, *(funks + your_pick));
    if(result == NULL)
    {
        printf("Failed to allocate memory");

        free(work);

        return 8;
    }

    printf("%s", result);

    free(work);
    free(result);

    return 0;
}
