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

int getFloat(float *pn) {
    char sign_char;
    float mult = 0.1;
    int c,
        sign,
        found_sign,
        i;

    while (isspace(c = getch())) {}

    if (!isdigit(c) &&
        c != EOF &&
        c != '+' &&
        c != '-' &&
        c != '.') {
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

    for (i = 0, *pn = 0;
         (isdigit(c) || c == '.');
         c = getch(), i += 1) {
        if (c == '.') {
            mult *= 0.1;
        } else {
            *pn = (10 * *pn) + (c - '0');
        }
    }

    *pn *= mult;
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    float i;

    getFloat(&i); // extremely naive; e.g. 222.22 => 222.220001

    printf("i is: %f\n", i);
    return 0;
}
