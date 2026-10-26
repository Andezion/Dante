#include <stdio.h>

unsigned int my_strlen(const char tab[]);
int my_atoi(const char tab[]);
float my_atof(const char tab[]);

int main(void) {
    char input[16] = "";

    printf("Enter number: ");
    if (scanf("%15[^\n]", input) != 1) {
        printf("Error\n");
        return 1;
    }

    printf("%u\n", my_strlen(input));
    printf("%d\n", my_atoi(input));
    printf("%.4f\n", my_atof(input));
    return 0;
}

static int is_digit(char c) {
    return c >= '0' && c <= '9';
}

unsigned int my_strlen(const char tab[]) {
    if (tab == NULL) {
        return 0;
    }

    unsigned int length = 0;
    while (tab[length] != '\0') {
        length++;
    }
    return length;
}

int my_atoi(const char tab[]) {
    if (tab == NULL) {
        return 0;
    }

    int i = 0;
    int sign = 1;
    if (tab[i] == '-' || tab[i] == '+') {
        sign = (tab[i] == '-') ? -1 : 1;
        i++;
    }

    int number = 0;
    for (; is_digit(tab[i]); i++) {
        number = number * 10 + (tab[i] - '0');
    }
    return sign * number;
}

float my_atof(const char tab[]) {
    if (tab == NULL) {
        return 0.0f;
    }

    int i = 0;
    float sign = 1.0f;
    if (tab[i] == '-' || tab[i] == '+') {
        sign = (tab[i] == '-') ? -1.0f : 1.0f;
        i++;
    }

    float number = 0.0f;
    for (; is_digit(tab[i]); i++) {
        number = number * 10 + (tab[i] - '0');
    }

    if (tab[i] == '.') {
        float scale = 0.1f;
        for (i++; is_digit(tab[i]); i++) {
            number += (tab[i] - '0') * scale;
            scale *= 0.1f;
        }
    }
    return sign * number;
}
