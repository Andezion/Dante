#include <stdio.h>
#include <stdint.h>

int longest_series(unsigned int x)
{
    int counter = 0;
    int max_counter = 0;

    for (int i = 31; i >= 0; --i)
    {
        int temp = (x >> i) & 1;

        if (temp == 1)
        {
            counter++;
            if (counter > max_counter)
            {
                max_counter = counter;
            }
        }
        else
        {
            counter = 0;
        }
    }

    return max_counter;
}

int main()
{
    int error;
    int32_t num;
    printf("Enter: ");

    error = scanf("%d", &num);
    if (error != 1)
    {
        printf("\nIncorrect input");
        return 1;
    }

    int32_t res = longest_series(num);
    printf("\n%d", res);

    return 0;
}
