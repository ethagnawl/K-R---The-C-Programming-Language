#include <stdio.h>

#define MAXIMUM_LINE_LENGTH 1000

void discard_newline(char *line_buffer);
void reverse(char *line_buffer);

int main(void) {
    char line[MAXIMUM_LINE_LENGTH];

    while(get_line(line, MAXIMUM_LINE_LENGTH) > 0) {
        discard_newline(line);
        reverse(line);
        printf("%s\n", line);
    }
}

void discard_newline(char input[]) {
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '\n') {
            input[i] = '\0';
        }
    }
}

// This is copied straight from the book, but the name is not intention
// revealing at all.
int get_line(char input[], int maximum_line_length) {
    int c,
        i;

    for (i = 0; i < maximum_line_length - 1 &&
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

void reverse(char input[]) {
    char temp;
    int i = -1,
        j = 0;

    while (input[i + 1] != '\0') {
        ++i;
    }

    for (j; j < i; j++) {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        --i;
    }
}
