#include <stdio.h>

main() {
    long nc;

    nc = 0;
    while (getchar() != EOF) {
        // also counts ENTER :/
        ++nc;
    }

    printf("%ld\n", nc);
}
