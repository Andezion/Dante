#include <stdio.h>

int main() {
    unsigned long long int result = 1;

    for (int i = 0; i <= 19; i++) {
        printf("%llu ", result), result *= 10;
    }

    return 0;
}
