#include <stdio.h>
#include <math.h>

float distance(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 && y1 == y2)
    {
        return -1.0f;
    }
    return sqrtf((float)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float perimeter(float a, float b, float c)
{
    if(a + b < c || a + c < b || b + c < a)
    {
        return -1.0f;
    }
    return (a + b + c);
}

float area(float a, float b, float c)
{
    if (a + b > c && b + c > a && c + a > b)
    {
        float p = perimeter(a, b, c) / 2;
        return sqrtf(p * (p - a) * (p - b) * (p - c));
    }
    return -1.0f;
}

int main()
{
    int x1, x2, x3;
    int y1, y2, y3;

    printf("Enter: ");
    int check1 = scanf("(%i, %i)",&x1, &y1);
    if(check1 != 2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    while(getchar() != '\n');

    printf("\nEnter: ");
    int check2 = scanf("(%i, %i)",&x2, &y2);
    if(check2 != 2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    while(getchar() != '\n');

    printf("\nEnter: ");
    int check3 = scanf("(%i, %i)",&x3, &y3);
    if(check3 != 2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }


    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);



    float result = area(a, b, c);
    if(result == -1)
    {
        printf("\nIncorrect input\n");
        return 1;
    }
    printf("\n%.2f\n",result);

    return 0;
}
