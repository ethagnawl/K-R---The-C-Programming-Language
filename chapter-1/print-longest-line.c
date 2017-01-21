#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);
void copy(char to[], char from[]);

main (void) {
    int length;
    int max;
    char line[MAX_LINE_LENGTH];
    char longest_line[MAX_LINE_LENGTH];

    max = 0;
    while((length = get_line(line, MAX_LINE_LENGTH)) > 0) {
        if (length > max) {
            max = length;
            copy(longest_line, line);
        }
    }

    if (max > 0) {
        printf("%s", longest_line);
    }

    return 0;
}

int get_line(char line[], int max_line_length) {
    int c,
        i;

    for (i = 0; i < (max_line_length - 1) &&
         (c = getchar()) != EOF &&
         c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

