#include <stdio.h>

int main(void)
{
    char letter = 0;

    printf("Enter letter: ");
    int check = scanf("%c", &letter);

    char lower = letter | 32;
    int is_letter = check == 1 && lower >= 'a' && lower <= 'z';
    int is_vowel  = lower == 'a' || lower == 'e' || lower == 'i' ||
                    lower == 'o' || lower == 'u' || lower == 'y';

    switch (is_letter * (2 - is_vowel))
    {
        case 1:
            printf("vowel");
            return 0;
        case 2:
            printf("consonant");
            return 0;
        default:
            printf("Incorrect input");
            return 1;
    }
}
