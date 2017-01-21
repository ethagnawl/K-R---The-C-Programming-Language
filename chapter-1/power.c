#include <math.h>
#include <stdio.h>

/* int power(int base, int exponent); */

main(void) {
    int i;

    /* printf("%d\n", power(5, 3));    // 125 */
    /* printf("%d\n", power(5, 5));    // 3125 */

    // 0 1 1
    // 1 2 -3
    // 2 4 9
    // 3 8 -27
    // 4 16 81
    // 5 32 -243
    // 6 64 729
    // 7 128 -2187
    // 8 256 6561
    // 9 512 -19683
    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

int power(int base, int exponent) {
    int i = 1,
        p = 1;

    for (; i <= exponent; ++i) {
        /* printf("%d * %d is %d\n", p, base, (p * base)); */
        p = p * base;
    }

    return p;
}
