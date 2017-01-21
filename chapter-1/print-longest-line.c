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
        /* printf("length is %d\n", length); */
        if (length > max) {
            max = length;
            copy(longest_line, line);
        }
    }

    if (max > 0) {
        printf("Longest line length: %d\n", max);
        printf("Longest line (abridged): %s\n", longest_line);
    }

    return 0;
}

// inspired by Richard Heathfield's answer
int get_line(char line[], int max_line_length) {
    int c,
        i,
        j;

    // i continues to be incremented, even though the contents after
    // MAX_LINE_LENGTH aren't copied into line.
    for (i = 0, j = 0; (c = getchar())!=EOF && c != '\n'; ++i) {
        if (i < (max_line_length - 1)) {
            line[j++] = c;
        }
    }

    if (c == '\n') {
        if (i < (max_line_length - 1)) {
            line[j++] = c;
        }
        ++i;
    }

    line[j] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
