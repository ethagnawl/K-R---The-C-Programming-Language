#include <stdio.h>
#include <string.h>

// inspired by: http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx305.html

void reverse(char s[]) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0,
        sign = n;

    if ( b <= 1 || b >= 37 ) {
        fprintf(stderr, "base %d is not supported.\n", b);
        return;
    }

    if (sign < 0) {
        n = abs(n);
    }

    do {
        s[i++] = digits[n % b];
    } while (n /= b);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

int main() {
    int base = 2,
        input;
    // buffer must be large enough to accommodate translated input
    char buffer[100] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    input = -63;
    itob(input, buffer, base);
    printf("%d in base %d is %s\n", input, base, buffer);
    // 63 in base 2 is 111111

    return 0;
}
