#include <stdio.h>
#include <stdlib.h>

int main() {
    int (*funcs)(int,int) = malloc (sizeof(int (*)(int, int)) * 4);
    if (funcs == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    int (*lower_to_upper)(int, int);
    int (*upper_to_lower)(int, int);
    int (*space_to_dash)(int, int);
    int (*reverse_letter)(int, int);

    *(funcs + 0) = int (*lower_to_upper)(int, int);

    int (*funcs[4])(int,int) =  { lower_to_upper,upper_to_lower,space_to_dash, reverse_letter};
    int operation;
    char * buffer = malloc(sizeof(char) * 1001);
    if (buffer == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj tekst: ");
    scanf("%1000[^\n]", buffer);
    while (getchar() != '\n');
    printf("Choose an operation: ");
    if (scanf("%d", &operation) != 1) {
        printf("Incorrect input");
        free(buffer);
        return 1;
    }
    if (operation < 0 || operation > 3) {
        printf("Incorrect input data");
        free(buffer);
        return 2;
    }

 //   char * wynik = letter_modifier(buffer, (*(funcs + operation)));
    if (wynik == NULL) {
        printf("Failed to allocate memory");
        free(buffer);
        return 8;
    }

    printf("%s", wynik);

    free(wynik);
    free(buffer);
    return 0;
}
