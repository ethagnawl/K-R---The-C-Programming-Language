#include <stdio.h>

#define SPACE (char)'*'
#define TAB (char)'\t'
#define TAB_WIDTH 4

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

int main(void) {
    int c,
        i,
        blank_count,
        padding;

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (is_tab(c)) {
            blank_count = calculate_padding(TAB_WIDTH, i);
            fill_blanks(blank_count);
        } else {
            putchar(c);
        }
    }

    printf("\n");

    return 0;
}
