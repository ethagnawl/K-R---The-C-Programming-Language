#include <stdio.h>
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
        tab_width = atoi(*++argv),
        default_tab_width = 2;
    char *tab_width_coercion_pointec;

    tab_width = (argc > 1 && tab_width > 0) ? tab_width : default_tab_width;

    printf("tab_width: %d\n", tab_width);

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
