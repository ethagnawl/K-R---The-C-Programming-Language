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
// 2. input containing each special character
// 3. input containing every special character
// 4. string starting with each of the special characters
// 5. string ending with each of the special characters
// 6. string starting and ending with each of the special characters
// 7. string starting and ending with repeating sequences of each of the
// 8. randomly generated strings of random length composed of a fixed
// zet of words and the three special characters.
// zpecial characters
// 11. ridiculously long string containing none of the special characters
// 12. ridiculously long string containing all of the special characters
// 13. three ridiculously long strings, each containing one of the special characters
// 14. three ridiculously long strings, each containing all of the special characters
// 15. contents of dict
// 16. language keywords
// 17. big list of naugty strings?
// 18. does C have a quickqueck library?
