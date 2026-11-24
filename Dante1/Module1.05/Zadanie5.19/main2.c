#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

char *letters = "aeiouy";

int counter(int *storage, int size) {
    if (storage == NULL) {
        return 0;
    }

    int max = 0;
    for (int i = 0; i < size; i++) {
        if (storage[i] > max) {
            max = storage[i];
        }
    }
    return max;
}

int main() {
    char string[1001];
    printf("Enter: ");
    if (fgets(string, sizeof(string), stdin) == NULL) {
        return 1;
    }

    int word_count = 0;
    int in_word = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isspace((unsigned char)string[i])) {
            in_word = 0;
        } else if (!in_word) {
            word_count++;
            in_word = 1;
        }
    }

    int *storage = (int *)calloc(word_count, sizeof(int));
    if (storage == NULL) {
        printf("Incorrect allocation\n");
        return 1;
    }

    int current_word = -1;
    in_word = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isspace((unsigned char)string[i])) {
            in_word = 0;
        } else {
            if (!in_word) {
                current_word++;
                in_word = 1;
            }
            for (int k = 0; letters[k] != '\0'; k++) {
                if (tolower((unsigned char)string[i]) == letters[k]) {
                    storage[current_word]++;
                    break;
                }
            }
        }
    }

    int max_number_of_vowels = counter(storage, word_count);
    for (int number_of_vowels = 0; number_of_vowels <= max_number_of_vowels; ++number_of_vowels) {
        int number_of_words = 0;
        for (int i = 0; i < word_count; i++) {
            if (storage[i] == number_of_vowels) {
                number_of_words++;
            }
        }
        if (number_of_words == 0) {
            continue;
        }
        printf("%d - %d\n", number_of_vowels, number_of_words);
    }

    free(storage);
    return 0;
}
