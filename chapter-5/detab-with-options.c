#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE (char)'*'
#define TAB (char)'\t'

int is_tab(char c) {
    return c == TAB;
}

int calculate_padding(int tab_width, int index) {
    return tab_width - (index % tab_width);
}

void fill_blanks(int blank_count) {
    int j;
    for (j = 0; j < blank_count; ++j) {
        putchar(SPACE);
    }
}

int main(int argc, char *argv[]) {
    int blank_count,
        c,
        i,
        padding,
        tab_width,
        default_tab_width = 2;
    char flag_head,
         recognized_flag = '+';

    flag_head = **++argv;
    char **flag_tail = &*argv++;
    int maybe_tab_width = atoi(*flag_tail);
    recognized_flag = '+';

    if (argc > 1 &&
        flag_head == recognized_flag &&
        maybe_tab_width > 0) {
        tab_width = maybe_tab_width;
    } else {
        tab_width = default_tab_width;
    }

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (is_tab(c)) {
            blank_count = calculate_padding(tab_width, i);
            fill_blanks(blank_count);
        } else {
            putchar(c);
        }
    }

    printf("\n");

    return 0;
}
