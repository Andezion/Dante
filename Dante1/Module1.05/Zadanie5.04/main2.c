#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[2000];
    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) != NULL) {

        size_t len = strlen(text);

        if (len > 0 && text[len - 1] == '\n')
        {
            len--;
        }
        if (len > 1000)
        {
            len = 1000;
        }

        printf("%zu", len);
    }

    return 0;
}
