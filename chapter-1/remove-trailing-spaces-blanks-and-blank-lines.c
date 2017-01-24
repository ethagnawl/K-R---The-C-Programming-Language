#include <stdio.h>

#define LINE_BUFFER_LENGTH 2222 // cheating

void flush_buffer(char *line_buffer);
void print_buffer(char *line_buffer, int end);

int main(void) {
    int c,
        i,
        line_index,
        all_spaces,
        last_char_index;
    char line_buffer[LINE_BUFFER_LENGTH];

    all_spaces = 1;
    line_index = 0;

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (c == '\n') {
            if (all_spaces == 0) {
                print_buffer(line_buffer, line_index);
            }
            flush_buffer(line_buffer);
            line_index = 0;
            all_spaces = 1;
        } else {
            if (line_index <= LINE_BUFFER_LENGTH) {
                if (c != ' ' && c != '\t') {
                    last_char_index = line_index;
                    all_spaces = 0;
                }
                line_buffer[line_index] = c;
                ++line_index;
            }
        }
    }

    if (all_spaces == 0) {
        print_buffer(line_buffer, line_index);
    }

    return 0;
}

void flush_buffer(char *line_buffer) {
    int i;
    for (i = 0; i <= LINE_BUFFER_LENGTH; ++i) {
        line_buffer[i] = 0;
    }
}

void print_buffer(char *line_buffer, int end) {
    int i;
    for (i = 0; i <= end; ++i) {
        putchar(line_buffer[i]);
    }
    printf("\n");
}
