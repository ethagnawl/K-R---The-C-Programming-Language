#include <stdio.h>

int ternary_lower(int c) {
    return c >= 'A' && c <= 'Z' ?
                                    c + 'a' - 'A' :
                                    c;
}

int main() {

    int C = 'C';
    int c = ternary_lower(C);   // c

    printf("lowercase %c is %c\n", C, c);

    int d = 'd';
    int dd = ternary_lower(d);  // d

    printf("lowercase %c is %c\n", d, dd);

    return 0;

}
