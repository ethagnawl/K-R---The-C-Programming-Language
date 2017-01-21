#include <stdio.h>

#define MIN_LINE_LENGTH 81

void print_buffer(char *line_buffer);

int main(void) {
    int c,
        i,
        line_index;
    char line_buffer[MIN_LINE_LENGTH];

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (c == '\n') {
            line_index = 0;
            continue;
        } else {
            ++line_index;
        }

        if (line_index < MIN_LINE_LENGTH) {
            line_buffer[line_index] = c;
        } else if (line_index == MIN_LINE_LENGTH) {
            print_buffer(line_buffer);
            putchar(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}

void print_buffer(char *line_buffer) {
    int i = 0;
    for (i = 0; i < MIN_LINE_LENGTH; ++i) {
        putchar(line_buffer[i]);
    }
}
