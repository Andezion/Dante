#include <stdio.h>

int main() {
    size_t power = 1;

    for (int i = 0; i <= 19; i++) {
        printf("10 do potegi %2d = %20zu\n", i, power);
        power *= 10;
    }

    return 0;
}
