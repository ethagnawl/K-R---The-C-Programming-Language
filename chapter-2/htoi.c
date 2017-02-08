#include <stdio.h>
#include <math.h>

#define MAX_STRING_LENGTH 1111

unsigned int hex_to_int(int h) {
    int i,
        result = -1;
    char hexidecimal[] = "0123456789ABCDEF";

    for (i = 0; i <= 15; ++i) {
        if (hexidecimal[i] == h) {
            result = i;
        }
    }

    /* printf("result is %d\n", result); */

    return result;
}

unsigned int htoi(char s[]) {
    int answer = 0;
    int exponent = 0;
    int i = 0;
    int hex_int;
    int term = 0;

    while (s[i] != '\0' && i < MAX_STRING_LENGTH) {
        ++i;
    }

    if (s[0] == '0' && s[1] == 'X') {
        term = 2;
    }

    while (i > term) {
        hex_int = hex_to_int(s[i - 1]);

        if (hex_int == -1) {
            answer = -1;
            break;
        } else {
             answer += hex_int * pow(16, exponent);
            ++exponent;
            --i;
        }
    }

    /* printf("answer is %d\n", answer); */

    return answer;
}

int main() {
    printf("0X0C0BE becomes: %d\n", htoi ("0X0C0BE"));   // 49342
    printf("F00 becomes: %d\n",     htoi ("F00"));       // 3840
    printf("FF3 becomes: %d\n",     htoi ("FF3"));       // 4083
    printf("FF becomes: %d\n",      htoi ("FF"));        // 255
    printf("F3 becomes: %d\n",      htoi ("F3"));        // 243
    printf("AF3 becomes: %d\n",     htoi ("AF3"));       // 2803 (10 16 16) + (15 16) + 3
    printf("G3 becomes: %d\n",      htoi ("G3"));        // -1

    return 0;
}
