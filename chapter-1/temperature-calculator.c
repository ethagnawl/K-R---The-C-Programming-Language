#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// print Fahrenheit - Celsius table
// for fahr = 0..300

float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_fahrenheit(float celsius);

main () {
    float fahr, celsius;

    printf("\nFahrenheit - Celsius\n");
    printf("==========\n");
    fahr = UPPER;
    while(fahr >= LOWER) {
        celsius = fahrenheit_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - STEP;
    }

    printf("\nCelsius - Fahrenheit\n");
    printf("==========\n");
    celsius = UPPER;
    while(celsius >= LOWER) {
        fahr = celsius_to_fahrenheit(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius - STEP;
    }
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}
