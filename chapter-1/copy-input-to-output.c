#include <stdio.h>

main() {
    int c;

    while((c = getchar()) != EOF) {
        printf("%d\n", (c != EOF));
    }
    printf("%d\n", (getchar() != EOF));
}
