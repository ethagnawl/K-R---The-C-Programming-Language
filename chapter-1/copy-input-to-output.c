#include <stdio.h>

main() {
    int c;

    while((c = getchar()) != EOF) {
        printf("%d\n", (c != EOF));     // prints 1
    }
    printf("%d\n", EOF); // ^d prints -1
}
