#include <stdio.h>
#include <string.h>

// exercise 5-3

int my_strcat(char *l, char *r) {
    while (*l != '\0') {
        l += 1;
    }

    while ((*l++ = *r++)) ;

    return 0;
}

int main() {
    char left[22];
    left[0] = 'h';
    left[1] = 'e';
    left[2] = 'l';
    left[3] = 'l';
    left[4] = 'o';
    left[5] = '\0';

    char right[22];
    right[0] = 'w';
    right[1] = 'o';
    right[2] = 'r';
    right[3] = 'l';
    right[4] = 'd';
    right[5] = '\0';

    my_strcat(left, right);
    char expected[] = "helloworld";
    int expected_result = strcmp(left, expected);

    printf("expected: %s\n", expected);
    printf("strcat'd left: %s\n", left);
    printf("result: %d\n", expected_result);

    return 0;
}
