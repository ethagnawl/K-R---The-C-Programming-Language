#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getch(void) {
    if (bufp > 0) {
        return buf[--bufp];
    } else {
        return getchar();
    }
}

int getInt(int *pn) {
    char sign_char;
    int c,
        sign,
        found_sign;

    while (isspace(c = getch())) {}

    if (!isdigit(c) &&
        c != EOF &&
        c != '+' &&
        c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        found_sign = 1;
        sign_char = c;
        c = getch();
    }

    if (!isdigit(c)) {
        ungetch(c);

        if (found_sign) {
            ungetch(sign_char);
        }

        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
                                               // when pn = 222
        printf("10 * *pn = %d\n", (10 * *pn)); // 0, 20, 220
        printf("c - '0' = %d\n", (c - '0'));   // 2 , 2, 2
        *pn = (10 * *pn) + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    int i;
    getInt(&i);
    printf("i is: %d\n", i);
    return 0;
}
