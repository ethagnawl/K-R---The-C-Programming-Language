// inspired by Rick Dearman's answer

#include <stdio.h>

#define FOLD_LENGTH 80
#define MAX_LINE_LENGTH 1000

// This is copied straight from the book, but the name is not intention
// revealing at all.
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

main() {
    int last_space,
        line_length,
        segment,
        segment_index;
    char line[MAX_LINE_LENGTH];

    while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
        if (line_length > FOLD_LENGTH) {
          segment = 0;
          segment_index = 0;

            while (segment < line_length) {
                if (line[segment] == ' ') {
                    last_space = segment;
                }
                if (segment_index == FOLD_LENGTH) {
                    line[last_space] = '\n';
                    segment_index = 0;
                }
                ++segment;
                ++segment_index;
            }
        }
      printf("%s", line);
    }

    return 0;
}
