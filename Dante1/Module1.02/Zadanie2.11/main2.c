#include <stdio.h>

int main(void) {
    printf("Enter a number from 0 to 10: ");

    char *data[] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec"};
    int number; 
    if (scanf("%d", &number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (number < 0 || number > 10) {
        printf("Incorrect input data\n");
        return 2;
    }

    printf("%s\n", data[number]);

    return 0;
}
