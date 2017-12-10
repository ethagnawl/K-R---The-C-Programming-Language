#include <stdio.h>
#include <string.h>

int my_strend(char *haystack, char *needle) {
    int haystack_length = strlen(haystack);
    int match = 1;
    int needle_length = strlen(needle);

    haystack += haystack_length;
    needle += needle_length;

    while (needle_length >= 0) {
        if (*haystack != *needle) {
            match = 0;
            break;
        } else {
            haystack -= 1;
            needle -= 1;
            needle_length -= 1;
        }
    }

    return match;
}

int main() {
    char haystack[] = "Hello, world.";
    char needle[] = "world.";

    printf("result: %d\n", my_strend(haystack, needle));

    char other_haystack[] = "This is the end.";
    char other_needle[] = "My only friend - the end.";

    printf("result: %d\n", my_strend(other_haystack, other_needle));

    return 0;
}
