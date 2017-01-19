#include <stdio.h>

#define CHARACTERS_LENGTH 256

main() {
    int c,
        i,
        j;
    int character_lengths[CHARACTERS_LENGTH + 1];

    for (i = 0; i < (CHARACTERS_LENGTH + 1); ++i) {
        character_lengths[i] = 0;
    }


    while ((c = getchar()) != EOF) {
        if (c < CHARACTERS_LENGTH) {
            ++character_lengths[c];
        } else {
            ++character_lengths[CHARACTERS_LENGTH];
        }
    }

    for (i = 1; i < (CHARACTERS_LENGTH + 1); ++i) {
        if ((i + 1) == (CHARACTERS_LENGTH + 1)) {
            // e.g. 255+    |*
            printf("%d+\t|", i - 1);
        } else {
            // e.g. a       |*
            printf("%d\t|", i);
        }

        for (j = 0; j < character_lengths[i]; j++) {
            printf("*");
        }

        printf("\n");
    }
}

// The following input:
// echo "!!! A BB CCC" | ./character-length-histogram
// Results in the following output:
// 10      |*   // LF
// ...
// 32      |*** // ' '
// 33      |*
// ...
// 65      |*   // A
// 66      |**  // B
// 67      |*** // C
