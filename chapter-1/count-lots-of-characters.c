#include <stdio.h>

main() {
    int c,
        blanks,
        newlines,
        tabs;

    blanks = 0;
    newlines = 0;
    tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        }
        if (c == '\n') {
            ++newlines;
        }
        if (c == '\t') {
            ++tabs;
        }
    }

    printf("blanks: %d\n", blanks);
    printf("newlines: %d\n", newlines);
    printf("tabs: %d\n", tabs);
}
