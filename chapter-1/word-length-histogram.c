#include <stdio.h>

#define MAX_WORD_LENGTH 11
#define WORD_LENGTHS_LENGTH 12

main() {
    int c,
        i,
        j,
        reached_max_length,
        word_length;
    int word_lengths[WORD_LENGTHS_LENGTH];

    reached_max_length = 0;
    word_length = 0;

    for (i = 0; i < WORD_LENGTHS_LENGTH; ++i) {
        word_lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (word_length > 0) {
                if (reached_max_length == 1) {
                    ++word_lengths[MAX_WORD_LENGTH];
                } else {
                    ++word_lengths[word_length];
                }
            }
            word_length = 0;
            reached_max_length = 0;
        } else {
            if (reached_max_length == 0) {
                ++word_length;
                if (word_length > MAX_WORD_LENGTH) {
                    reached_max_length = 1;
                }
            }
        }
    }

    for (i = 1; i < WORD_LENGTHS_LENGTH; ++i) {
        if ((i + 1) == WORD_LENGTHS_LENGTH) {
            // e.g. 10+    |
            printf("%d+\t|", i - 1);
        } else {
            // e.g. 1      |
            printf("%d\t|", i);
        }
        for (j = 0; j < word_lengths[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// The following input:
// echo "1 22 22 333 333 333 4444 4444 4444 4444 55555 55555 55555 55555 55555
//       666666 666666 666666 666666 666666 666666 7777777 7777777 7777777
//       7777777 7777777 7777777 7777777 88888888 88888888 88888888 88888888
//       88888888 88888888 88888888 88888888 999999999 999999999 999999999
//       999999999 999999999 999999999 999999999 999999999 999999999 1010101010
//       1010101010 1010101010 1010101010 1010101010 1010101010 1010101010
//       1010101010 1010101010 1010101010 11111111111"
//       | ./word-length-histogram */
// Results in the following output:
// 1       |*
// 2       |**
// 3       |***
// 4       |****
// 5       |*****
// 6       |******
// 7       |*******
// 8       |********
// 9       |*********
// 10      |**********
// 10+     |*
