#include <stdio.h>
#include <string.h>

int main()
{
    char array[101];
    printf("Enter: ");
    scanf("%100[^\n]", array);


    if(strlen(array) > 50)
    {
        printf("\nInput is too long");
        return 1;
    }

    int max_number_nawiasy = 0;
    int dupochka_value = 0;

    int hihi_haha_value = 0;

    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == '(')
        {
            hihi_haha_value++;

            if (hihi_haha_value > max_number_nawiasy)
            {
                max_number_nawiasy = hihi_haha_value;
                dupochka_value = 1;
            }
            if (hihi_haha_value == max_number_nawiasy)
            {
                dupochka_value++;
            }
        }
        if (array[i] == ')')
        {
            hihi_haha_value--;
        }
    }

    printf("\n");
    printf("%i ", max_number_nawiasy);

    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == '(')
        {
            hihi_haha_value++;
            if (hihi_haha_value == max_number_nawiasy)
            {
                printf("%i ", i);
            }
        }
        if (array[i] == ')')
        {
            hihi_haha_value--;
        }
    }

    return 0;
}
