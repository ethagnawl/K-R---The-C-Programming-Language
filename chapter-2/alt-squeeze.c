#include <stdio.h>

// Inspiration drawn from Andrew Heathfield's answer
// http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx204.html

void alt_sqeeze(char haystack[], char needles[]) {
    int i,
        j,
        k,
        match;

    for (i = j = 0; haystack[i] != '\0'; ++i) {
        match = 0;

        for (k = 0; needles[k] != '\0' && !match; ++k) {
            if (needles[k] == haystack[i]) {
                match = 1;
            }
        }

        if (!match) {
            // use current value of j and then increment
            haystack[j++] = haystack[i];
        }
    }

    haystack[j] = '\0';
}

int main() {

    char needles[] = "aeiouy";
    char haystack[] = "The alderman had oddly shaped feet.";

    alt_sqeeze(haystack, needles);

    printf("haystack is now: %s\n", haystack);
        // => haystack is now: Th ldrmn hd ddl shpd ft.

    return 0;
}
