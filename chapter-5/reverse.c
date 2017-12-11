#include <stdio.h>
#include <string.h>

int my_reverse(char *input) {
    // assistance from: https://stackoverflow.com/a/15718000/382982
    char popped;
    char *_input = input;
    char *end_of_input = _input + strlen(input) - 1;

    while (end_of_input > _input) {
        popped = *end_of_input;
        *end_of_input-- = *_input;
        *_input++ = popped;
    }

    return 0;
}

int main() {
    char my_word[] = "olleh";
    my_reverse(my_word);
    printf("reversed my_word: %s\n", my_word);
    return 0;
}
