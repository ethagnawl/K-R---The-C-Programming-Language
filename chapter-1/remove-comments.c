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

int contains_leading_slash_star(char line[]) {
    if (line[0] == '/' &&
        line[1] == '*') {
        return 1;
    } else {
        return 0;
    }
}

int contains_leading_double_slash(char line[]) {
    if (line[0] == '/' &&
        line[1] == '/') {
        return 1;
    } else {
        return 0;
    }
}

int contains_trailing_slash_star(int line_length, char line[]) {
    if (line[line_length - 3] == '*' &&
        line[line_length - 2] == '/') {
        return 1;
    } else {
        return 0;
    }
}

int begins_string(int i, char line[]) {
    int response = 0;

    if (line[i] == '"') {
        response = 1;
    } else {
        response = 0;
    }

    return response;
}

int ends_string(int i, char line[]) {
    int response = 0;

    if (line[i] == '"') {
        response = 1;
    } else {
        response = 0;
    }

    return response;
}

int begins_inline_comment(int i, int line_length, char line[]) {
    int response = 0;

    if (i + 1 > line_length) {
        response = 0;
    } else if (line[i] == '/' &&
               line[i + 1] == '*') {
        response = 1;
    } else {
        response = 0;
    }

    return response;
}

int ends_inline_comment(int i, int line_length, char line[]) {
    int response = 0;

    if (i + 1 > line_length) {
        response = 0;
    } else if (line[i] == '*' &&
               line[i + 1] == '/') {
        response = 1;
    } else {
        response = 0;
    }

    return response;
}

int begins_line_ending_comment(int i, int line_length, char line[]) {
    int response = 0;

    if (i + 1 > line_length) {
        response = 0;
    } else if (line[i] == '/' &&
               line[i + 1] == '/') {
        response = 1;
    } else {
        response = 0;
    }

    return response;
}

int main() {
    int i,
        in_comment,
        in_string,
        line_length;
    char line[MAX_LINE_LENGTH];

    in_comment = 0;
    in_string = 0;

    while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
        if (in_comment == 1) {
            continue;
        } else if (contains_leading_double_slash(line)) {
            continue;
        } else if (contains_leading_slash_star(line)) {
            in_comment = 1;
            continue;
        } else if (contains_trailing_slash_star(line_length, line)) {
            in_comment = 0;
            continue;
        } else {
            if (!in_comment) {
                for (i = 0; i < line_length; ++i) {
                    if (in_string == 0 &&
                        begins_line_ending_comment(i, line_length, line)) {
                        putchar('\n');
                        break;
                    } else if (in_string == 0 &&
                               begins_inline_comment(i, line_length, line)) {
                        in_comment = 1;
                        i += 2;
                        continue;
                    } else if (in_string == 0 &&
                               ends_inline_comment(i, line_length, line)) {
                        in_comment = 0;
                        i += 2;
                        continue;
                    } else if (in_comment == 0 &&
                               in_string == 0 &&
                               begins_string(i, line)) {
                        in_string = 1;
                        putchar(line[i]);
                    } else if (in_comment == 0 &&
                               in_string == 1 &&
                               ends_string(i, line)) {
                        in_string = 0;
                        putchar(line[i]);
                    } else if (in_comment == 1) {
                        continue;
                    } else {
                        putchar(line[i]);
                    }
                }
            }
        }
    }

    return 0;
}
