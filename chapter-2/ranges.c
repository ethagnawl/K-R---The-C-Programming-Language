#include <stdio.h>
#include <limits.h>

int main() {

    // char
    printf("Size of char: %d\n", CHAR_BIT);
    printf("Size of (unsigned) char %d\n", UCHAR_MAX);
    printf("Char min: %d\n", CHAR_MIN);
    printf("Char max: %d\n", CHAR_MAX);

    // int
    // Why is there no INT_BIT?
    printf("Size of (unsigned) int %d\n", UINT_MAX);
    printf("Int min: %d\n", INT_MIN);
    printf("Int max: %d\n", INT_MAX);

    // long
    printf("Size of (unsigned) long %d\n", ULONG_MAX);
    printf("Long min: %d\n", LONG_MIN);
    printf("Long max: %d\n", LONG_MAX);

    // short
    printf("Size of (unsigned) short %d\n", USHRT_MAX);
    printf("Short min: %d\n", SHRT_MIN);
    printf("Short max: %d\n", SHRT_MAX);

    return 0;
}
