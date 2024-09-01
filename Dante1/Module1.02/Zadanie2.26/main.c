#include <stdio.h>

int main()
{
    char letter;

    printf("Enter letter: ");
    int number;
    int check = scanf("%c",&letter);
    switch (check)
    {
        case 1:
            number = (letter == 'a') * 1 + (letter == 'q') * 2 + (letter == 'e') * 1 + (letter == 'i') * 1 + (letter == 'u') * 1 + (letter == 'o') * 1 +
                     (letter == 'A') * 1 + (letter == 'Q') * 2 + (letter == 'E') * 1 + (letter == 'I') * 1 + (letter == 'U') * 1 + (letter == 'O') * 1 +
                     (letter == 'b') * 2 + (letter == 'c') * 2 + (letter == 'd') * 2 + (letter == 'f') * 2 + (letter == 'g') * 2 + (letter == 'h') * 2 +
                     (letter == 'j') * 2 + (letter == 'k') * 2 + (letter == 'l') * 2 + (letter == 'm') * 2 + (letter == 'n') * 2 + (letter == 'p') * 2 +
                     (letter == 'r') * 2 + (letter == 's') * 2 + (letter == 't') * 2 + (letter == 'v') * 2 + (letter == 'w') * 2 + (letter == 'x') * 2 +
                     (letter == 'z') * 2 + (letter == 'y') * 1 + (letter == 'Y') * 1 + (letter == 'B') * 2 + (letter == 'C') * 2 + (letter == 'D') * 2 +
                     (letter == 'F') * 2 + (letter == 'G') * 2 + (letter == 'H') * 2 + (letter == 'J') * 2 + (letter == 'K') * 2 + (letter == 'L') * 2 +
                     (letter == 'M') * 2 + (letter == 'N') * 2 + (letter == 'P') * 2 + (letter == 'R') * 2 + (letter == 'S') * 2 + (letter == 'T') * 2 +
                     (letter == 'V') * 2 + (letter == 'W') * 2 + (letter == 'X') * 2 + (letter == 'Z') * 2;
            switch (number)
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
        default:
            printf("Incorrect input");
            return 1;
    }
}
