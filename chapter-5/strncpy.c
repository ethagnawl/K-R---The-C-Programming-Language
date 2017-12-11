#include <stdio.h>

int my_strncpy(char *input, char *output, int length) {
    int i = 0;

    while ((*output++ = *input++)) {
        i += 1;

        if (i == length) {
            break;
        }
    }

    return 0;
}

int main() {
    char input[] =  "xxx";
    char output[] = "yyy";

    my_strncpy(input, output, 3);

    printf("output: %s\n", output); // xxx

    return 0;
}
