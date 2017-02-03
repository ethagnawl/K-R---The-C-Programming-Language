#include <stdio.h>

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

int main() {
    int curly_brackets,
        i,
        in_double_quote,
        in_single_quote,
        line_length,
        parentheses,
        square_brackets;
    char line[MAX_LINE_LENGTH];

    curly_brackets = 0;
    parentheses = 0;
    in_double_quote = 0;
    in_single_quote = 0;
    square_brackets = 0;

    while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
        for (i = 0; i < line_length; ++i) {
            if (line[i] == '(') {
                ++parentheses;
            } else if (line[i] == ')') {
                --parentheses;
            } else if (line[i] == '{') {
                ++curly_brackets;
            } else if (line[i] == '}') {
                --curly_brackets;
            } else if (line[i] == '[') {
                ++square_brackets;
            } else if (line[i] == ']') {
                --square_brackets;
            } else if (line[i] == '\'') {
                if (in_single_quote) {
                    in_single_quote = 0;
                } else {
                    in_single_quote = 1;
                }
            } else if (line[i] == '"') {
                if (in_double_quote) {
                    in_double_quote = 0;
                } else {
                    in_double_quote = 1;
                }
            }
        }
    }

    /* printf("curly brackets: %d\n", parentheses); */
    /* printf("double quotes: %d\n", in_single_quote); */
    /* printf("parentheses: %d\n", parentheses); */
    /* printf("single quotes: %d\n", in_single_quote); */
    /* printf("square brackets: %d\n", square_brackets); */

    if (curly_brackets != 0) {
        printf("Unbalanced curly brackets\n");
    } else if (in_double_quote != 0) {
        printf("Unbalanced double quotes\n");
    } else if (in_single_quote != 0) {
        printf("Unbalanced single quotes\n");
    } else if (parentheses != 0) {
        printf("Unbalanced parentheses\n");
    } else if (square_brackets != 0) {
        printf("Unbalanced square brackets\n");
    } else {
        printf("Success!\n");
    }

    return 0;
}
