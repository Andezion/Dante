#include <stdio.h>

int main() {
    char string[1000];
    printf("Enter: ");
    fgets(string, sizeof(string), stdin);

    int coding = 0;
    printf("Enter coding: ");
    if (scanf("%d", &coding) != 1 || coding < 0) {
        printf("Incorrect input\n");
        return 1;
    }

    if (coding > 26) {
        coding = coding % 26;
    }

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = ((string[i] - 'A' + coding) % 26) + 'A';
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = ((string[i] - 'a' + coding) % 26) + 'a';
        }
    }

    printf("%s", string);

    return 0;
}
