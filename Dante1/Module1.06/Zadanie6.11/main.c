#include <stdio.h>
#include <math.h>

int main()
{
    int matrix[10][10];

    printf("Enter data:\n");

    int max = -__INT_MAX__;
    int max_i;
    int max_j;

    int min = __INT_MAX__;
    int min_i;
    int min_j;

    int sum = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int check = scanf("%i", &matrix[i][j]);
            if(check != 1)
            {
                printf("Incorrect input\n");
                return 1;
            }

            sum += matrix[i][j];
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
                max_i = i;
                max_j = j;
            }
            if(matrix[i][j] < min)
            {
                min = matrix[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }

    int middle = sum / (10 * 10);

    int count1 = 0, count2 = 0, count3 = 0;
    int middle_i, middle_j;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(matrix[i][j] == max)
            {
                count1++;
            }
            if(matrix[i][j] == min)
            {
                count2++;
            }
            if(matrix[i][j] == middle)
            {
                count3++;
                middle_i = i;
                middle_j = j;
            }
        }
    }

    if(count1 != 1 || count2 != 1 || count3 != 1)
    {
        printf("Error\n");
        return 2;
    }

    float dist1 = sqrtf(powf(min_i - max_i, 2) + powf(min_j - max_j, 2));
    float dist2 = sqrtf(powf(middle_i - min_i, 2) + powf(middle_j - min_j, 2));
    float dist3 = sqrtf(powf(max_i - middle_i, 2) + powf(max_j - middle_j, 2));

    printf("%.2f %.2f %.2f\n", dist1, dist2, dist3);

    return 0;
}
