#include <stdio.h>

// print Fahrenheit - Celcius table
// for fahr = 0..300

main () {
    float fahr, celsius;
    int lower,
        upper,
        step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = upper;

    printf("Fahrenheit - Celcius\n");
    printf("==========\n");
    while(fahr >= lower) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }

    printf("Celcius - Fahrenheit \n");
    printf("==========\n");
    celsius = upper;
    while(celsius >= lower) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius - step;
    }
}
