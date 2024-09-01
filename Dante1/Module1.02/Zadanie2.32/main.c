#include <stdio.h>

int main()
{
    int num1, num2;
    char type;

    printf("Enter numbers: ");
    int check1 = scanf("%i %i",&num1,&num2);
    switch (check1)
    {
        case 2:
            printf("Enter type: ");

            //while (getchar() != '\n');
            scanf("%*[^\n]"); // Считываем и игнорируем все символы до символа новой строки
            scanf("%*c");
            int check2 = scanf("%c",&type);

            switch (check2)
            {
                case 1:
                    switch (type)
                    {
                        case '+':
                            printf("%i",num1 + num2);
                            return 0;
                        case '-':
                            printf("%i",num1 - num2);
                            return 0;
                        case '*':
                            printf("%i",num1 * num2);
                            return 0;
                        case '/':
                            switch (num2)
                            {
                                case 0:
                                    printf("Illegal operation");
                                    return 2;
                                default:
                                    printf("%.2f",(float)num1 / (float) num2);
                                    return 0;
                            }
                    }
                default:
                    printf("Incorrect input");
                    return 1;
            }
        default:
            printf("Incorrect input");
            return 1;
    }
}
