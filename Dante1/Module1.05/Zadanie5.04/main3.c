#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter: ");

    char text[1001];
    scanf("%1000[^\n]", text);
    printf("%lu\n", strlen(text));
    return 0;
}
