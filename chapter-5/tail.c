#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 999
#define MAX_LINES 999
#define MAX_SHOW_N_LINES 999

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

int main(int argc, char *argv[]) {
    int show_n_lines = 10,
        i = 0,
        j,
        line_length,
        maybe_show_n_lines;
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char (*lines_ptr)[MAX_LINE_LENGTH] = lines;


    if (argc > 1) {
        char *flag_ptr = *++argv;
        if (*flag_ptr == '-') {
            maybe_show_n_lines = atoi(++flag_ptr);
        }
    }

    if (maybe_show_n_lines > 0) {
        show_n_lines = maybe_show_n_lines;
    }

    // copy lines into multi-dimensional array
    while (line_length = get_line(lines[i], MAX_LINE_LENGTH)) {
        i += 1;
        lines_ptr++;
    }

    // if there are more lines than there are "lines to show", show all lines
    if (show_n_lines > i) {
        show_n_lines = i;
    }

    if (show_n_lines > MAX_SHOW_N_LINES) {
        show_n_lines = MAX_SHOW_N_LINES;
    }

    // wind pointer back show_n_lines
    j = i;
    while (j > (i - show_n_lines)) {
        --lines_ptr;
        j -= 1;
    }

    while (j <= i) {
        printf("%s", *lines_ptr++);
        j += 1;
    }

    return 0;
}
