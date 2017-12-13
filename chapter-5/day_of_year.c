#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 21},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 21}
};

int day_of_year(int year, int month, int day) {
    int i,
        leap;

    if (month < 1 || month > 12) {
        return -1;
    } else if (day < 1 || day > 31) {
        return -1;
    }

    leap = year % 4 == 0 && (year % 100 != 0 ||
                             year % 400 == 0);

    for (i = 0; i < month; i += 1) {
        day += daytab[leap][i];
    }

    return day;
}

int main() {
    int my_day = day_of_year(2020, 12, 42);
    printf("%d\n", my_day);
    return 0;
}
