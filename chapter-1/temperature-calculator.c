#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// print Fahrenheit - Celcius table
// for fahr = 0..300

main () {
    float fahr, celsius;

    printf("Fahrenheit - Celcius\n");
    printf("==========\n");
    fahr = UPPER;
    while(fahr >= LOWER) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - STEP;
    }

    printf("Celcius - Fahrenheit \n");
    printf("==========\n");
    celsius = UPPER;
    while(celsius >= LOWER) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius - STEP;
    }
}
