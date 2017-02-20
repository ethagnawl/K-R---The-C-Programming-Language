#include <stdio.h>

// inspired by Paul Griffiths' answer:
// http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx302.html

// TODO: Why wasn't I able to allocate separate, distinct
// unescape_input/unescape_output strings and operate on them accordingly?
// They worked as expected in isolation, but for some reason, the escape
// operation and its variables were affecting the output of
// unescape_input/unescape_output (messing with the length and format of
// unescape_input).

void escape(char *input, char *output) {
    int i = 0,
        j = 0;

    while (input[i] != '\0') {
        switch(input[i]) {

            case '\n':
                output[j++] = '\\';
                output[j] = 'n';
                break;

            case '\t':
                output[j++] = '\\';
                output[j] = 't';
                break;

            default:
                output[j] = input[i];
                break;
        }
        ++i;
        ++j;
    }

    output[j] = '\0';
}

void unescape(char *input, char *output) {
    int i = 0,
        j = 0;

    while (input[i]) {

        switch (input[i]) {

            case '\\':

                switch(input[++i]) {

                    case 'n':
                        output[j] = '\n';
                        break;

                    case 't':
                        output[j] = '\t';
                        break;

                    default:
                        output[j++] = '\\';
                        output[j] = input[i];
                        break;

                }

                break;

            default:
                output[j] = input[i];
                break;

        }

        i++;
        j++;

    }

    output[j] = '\0';

}

int main() {

    // escape
        printf("\nescape: --------------------------\n");

        char escape_input[13] = "foo\t\tbar.\nEOF";
        int escape_input_i = 0;
        int escape_output_i = 0;
        // Ensure that the additional escape characters won't cause an overflow.
        // This loop sets escape_output_i to escape_input.length * 2, which is
        // a bit crude, but works. A better solution would be to iterate through
        // escape_input and determine exactly how many characters are going to be
        // escaped and pad escape_output accordingly.
        while (escape_input[escape_input_i] != '\0') {
            escape_output_i += 2;
            escape_input_i++;
        }
        char escape_output[escape_output_i];


        /* escape_input is: foo           bar. */
        /* EOF */
        printf("escape_input is: %s\n", escape_input);

        escape(escape_input, escape_output);

        /* escape_output is: foo\t\tbar.\nEOF */
        printf("escape_output is: %s\n", escape_output);

    // unescape
        printf("\nunescape: --------------------------\n");

        /* unescape_input is: foo\t\tbar.\nEOF */
        printf("unescape_input is: %s\n", escape_output);

        // unescape
        unescape(escape_output, escape_input);

        /* escape_output is: foo           bar. */
        /* EOF */
        printf("unescape_output is: %s\n", escape_input);

    return 0;

}
