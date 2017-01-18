#include <stdio.h>

#define IN 1
#define OUT 0

main() {
    int c,
        nl,
        nw,
        nc,
        state;

    state = OUT;
    nl = nw = nc = 0;

    while((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}

// 1-11
// (It should go without saying that all of the following should be
// automated.)
// 1. empty string
// 2. string starting with each of the special characters
// 3. string ending with each of the special characters
// 4. string starting and ending with each of the special characters
// 5. string starting and ending with repeating sequences of each of the
// special characters
// 6. ridiculously long string
// 7. contents of dict
// 8. language keywords
// 9. big list of naugty strings?
