#include <stdio.h>
#include <string.h>

size_t custom_index(const char *str, char c) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    printf("Enter: ");

    int data[12] = { 0 };
    char letters[] = "aAeEiIoOuUyY";

    char text[1001];
    scanf("%1000[^\n]", text);

    int counter = 0;
    for (size_t i = 0; i < strlen(text); i++) {
        size_t index = custom_index(letters, text[i]);
        if (strchr(letters, text[i]) != NULL && data[index] == 0) {
            counter++;
            data[index] = 1;
        }
    }

    printf("%d\n", counter);

    return 0;
}
