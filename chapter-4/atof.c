#include <stdio.h>

// inspired by: https://github.com/thomas-scrace/My-K-R-Exercise-Solutions/blob/master/c4/4.2/ex_4-2/atof.c
// However, my implementation seems to be broken.
// e.g. 2.537e2 => 253 and not 253.7

double atof(char s[]) {
	double val, power, result, sci;
	int i, sign, esign, exp;

	for (i = 0; isspace(s[i]); i++)	{ ; }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        sign = 1;
        i++;
    } else {
        sign = 1;
    }

	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
    }

	if (s[i] == '.') {
		i++;
    }

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }

    if (s[i] == '+') {
        esign = 1;
        i++;
    } else if (s[i] == '-') {
        esign = -1;
        i++;
    } else {
        esign = 1;
    }

    for (exp = 0; isdigit(s[i]); i++) {
        exp = 10 * exp + (s[i] - '0');
    }

    sci = 1;

    if (esign == 1) {
        while (exp > 0) {
            sci *= 10;
            exp--;
        }
    } else if (esign == -1) {
        while (exp > 0) {
            sci /= 10;
            exp--;
        }
    } else {
        printf("Don't know what to do with esign: %d\n", esign);
    }

    // printf("sign: %d\n", sign);
    // printf("val: %d\n", val);
    // printf("power: %d\n", power);
    // printf("sci: %d\n", sci);

    result = (sign * val / power) * sci;

    return result;
}

int main() {
    int result;
    char input[8] = "2.537e2";
    double d = 0;
    printf("--------------------------------------------------------------------------------\n");
    result = atof(input);
    printf("result is %d\n", result); // result is 123000000
    return 0;
}
