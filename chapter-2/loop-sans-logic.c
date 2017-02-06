#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int maximum_line_length) {
    int c,
        i;

    i = 0;

    while (i < maximum_line_length) {
        c = getchar();

        if (c == EOF) {
            break;
        } else if (c == '\n') {
            break;
        } else {
            line[i] = c;
        }

        ++i;
    }

    line[i] = '\0';

    return i;
}

main() {
    int i,
        line_length;
    char line[MAX_LINE_LENGTH];

    i = 0;

    while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {

        for (i = 0; i < line_length; ++i) {
            putchar(line[i]);
        }

        putchar('\n');
    }

    return 0;
}
