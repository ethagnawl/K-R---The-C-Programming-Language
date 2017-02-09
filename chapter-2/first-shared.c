#include <stdio.h>

#define MAX_STRING_LENGTH 1111

int any(char haystack[], char needle[]) {
    int i;
    int j;
    int result = -1;
    int haystack_length = 0;
    int needle_length = 0;

    while (haystack[haystack_length] != '\0' && haystack_length < MAX_STRING_LENGTH) {
        ++haystack_length;
    }

    while (needle[needle_length] != '\0' && needle_length < MAX_STRING_LENGTH) {
        ++needle_length;
    }

    for (i = 0; i < haystack_length; ++i) {

        for (j = 0; j < needle_length; ++j) {
            if (haystack[i] == needle[j]) {
                result = i;
                break;
            }
        }

        if (result > -1) {
            break;
        }

    }

    return result;
}

int main() {
    int location;

    location = any("foobar", "r"); // location is 5
    printf("location is %d\n", location);

    location = any("foobar", "x"); // location is -1
    printf("location is %d\n", location);

    return 0;
}
