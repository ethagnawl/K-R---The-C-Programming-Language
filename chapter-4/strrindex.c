#include <stdio.h>
#include <string.h>

int strrindex(char haystack[], char needle[]) {
    int match_index = -1,
        haystack_length = strlen(haystack) - 1,
        needle_length = strlen(needle) - 1,
        i,
        k;

    i = haystack_length;

    while (i >= 0) {
        if (haystack[i] == needle[needle_length]) {
            for (k = 0; k <= needle_length; k++) {
                if (needle[needle_length - k] == haystack[i - k]) {
                    match_index = i - k;
                }
            }
            match_index = (match_index == i - needle_length) ? match_index : -1;
        }

        if (match_index > -1) {
            break;
        } else {
            i--;
        }
    }

    return match_index;
}

int main() {
    char haystack[47] = "that depends on what your definition of is is",
         needle[3] = "is";
    int index;

    index = strrindex(haystack, needle);

    printf("'%s' was found at %d\n", needle, index); // 'is' was found at 43

    return 0;
}
