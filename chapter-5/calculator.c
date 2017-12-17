#include <stdio.h>
#include <stdlib.h>

const char *usage = "Usage: `calc 2 2 *`";

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("%s\n", usage);
    } else {
        char *endptr;
        int result;
        int operand_one = strtol((*++argv), &endptr, 10);
        int operand_two = strtol((*++argv), &endptr, 10);
        char operator = *(*++argv);

        if (operator == '*') {
            result = operand_one * operand_two;
            printf("Result: %d\n", result);
            return result;
        } else {
            printf("'%c' is not a supported operation.\n", operator);
            return -1;
        }

    }
    return 0;
}
