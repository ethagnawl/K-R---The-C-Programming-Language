#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 999

char * in_same_range(char haystack[], char needle) {
    return strchr(haystack, needle);
}

void expand(char *input, char *output) {
    char digits[11] = "0123456789";
    char lowercase_alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0,
        valid_range = 0;
    char *start,
         *end,
         *index;

    if (input[1] == '-') {

        if ((start = in_same_range(digits, input[i])) &&
            (end  = in_same_range(digits, input[i+2]))) {
            valid_range = 1;
        } else if ((start = in_same_range(lowercase_alphabet, input[i])) &&
                   (end  = in_same_range(lowercase_alphabet, input[i+2]))) {
            valid_range = 1;
        } else if ((start = in_same_range(uppercase_alphabet, input[i])) &&
                   (end  = in_same_range(uppercase_alphabet, input[i+2]))) {
            valid_range = 1;
        } else {
            printf("Unable to handle specified range: %s\n", input);
        }

        if (valid_range) {
            index = start;
            while (index <= end) {
                output[i++] = *index;
                index++;
            }
        }

    }

    output[i] = '\0';
}

int main() {
    printf("-----------------------\n");

    char digit_input[4] = "1-3";
    char digit_output[MAX_STRING_LENGTH];
    expand(digit_input, digit_output);
    printf("digit_ouput is %s\n", digit_output); // 123

    char uppercase_input[4] = "T-W";
    char uppercase_output[MAX_STRING_LENGTH];
    expand(uppercase_input, uppercase_output);
    printf("uppercase_ouput is %s\n", uppercase_output); // TUVW

    char lowercase_input[4] = "b-f";
    char lowercase_output[MAX_STRING_LENGTH];
    expand(lowercase_input, lowercase_output);
    printf("lowercase_ouput is %s\n", lowercase_output); // bcdef

    return 0;
}
