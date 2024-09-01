#include <stdio.h>
#include <math.h>

int main()
{
    float number1, image1;
    float number2, image2;
    char what1, what2;

    char buffer[10];


    printf("Enter num1: ");
    scanf("%f",&number1);

    printf("Enter ima1: ");
    scanf("%f",&image1);
    sprintf(buffer,"%+f",image1);
    what1 = buffer[0];

    printf("Enter num2: ");
    scanf("%f",&number2);

    printf("Enter ima2: ");
    scanf("%f",&image2);
    sprintf(buffer,"%+f",image2);
    what2 = buffer[0];

    printf("First is: %.3f %c i%.3f\n",number1, what1, fabsf(image1));
    printf("Second is: %.3f %c i%.3f\n",number2, what2, fabsf(image2));

    char prob1;
    float problem1 = image1 + image2;
    sprintf(buffer,"%+f",problem1);
    prob1 = buffer[0];

    printf("Suma is: %.3f %c i%.3f\n",number1 + number2,prob1, fabsf(image1 + image2));

    char prob2;
    float problem2 = image1 - image2;
    sprintf(buffer,"%+f",problem2);
    prob2 = buffer[0];

    printf("Minus is: %.3f %c i%.3f\n",number1 - number2,prob2, fabsf(image1 - image2));

    char prob3;
    float problem3 = image1 * number2 + number1 * image2;
    sprintf(buffer,"%+f",problem3);
    prob3 = buffer[0];

    printf("Multi is: %.3f %c i%.3f\n",number2 * number1 - image2 * image1,prob3, fabsf(image1 * number2 + number1 * image2));

    char prob4;
    float problem4 = (image1 * number2 - number1 * image2) / (image1 * image1 + image2 * image2);
    sprintf(buffer,"%+f",problem4);
    prob4 = buffer[0];

    printf("Divide is: %.3f %c i%.3f\n",((number2 * number1 + image2 * image1) / (number2 * number2 + image2 * image2)),prob4, fabsf(((image1 * number2 - number1 * image2) / (number2 * number2 + image2 * image2))));


    return 0;
}
