#include <stdio.h>
#include <string.h>

int get_line(char input[], int maximum_line_length) {
    int c,
        i,
        j;

    for (i = 0; i < maximum_line_length &&
                (c = getchar()) != EOF &&
                c != '\n'; ++i) {
        input[i] = c;
    }

    if (c == '\n') {
        input[i++] = c;
    }

    input[i] = '\0';

    return i;
}

int my_read_lines(char lines[][3]) {
    int i = 0;
    char line[100];
    while (i < 3) {
        get_line(lines[i], 100);
        // If this line is elided, the line lengths accumulate.
        // Also, isn't line 19 already doing this?
        // Color me confused ...
        lines[i][2] = '\0';
        i += 1;
    }
    return 0;
}

// Hardcoded, contrived, junk but I wanted to be sure to get a feel for
// nested arrays/pointers.
int main() {
    int i = 0;
    char lines[3][3];

    my_read_lines(lines);

    for (i; i < 3; i += 1) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
