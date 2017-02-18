#include <stdio.h>
#include <time.h>

#define MAX_ELEMENT 20000

// Inspired by Colin Barker's solution on:
// http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx301.html

int binary_search(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while ( low <= high ) {
        mid = (low+high) / 2;
        if ( x < v[mid] )
            high = mid - 1;
        else if ( x > v[mid] )
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int faster_binary_search(int x, int v[], int n) {
    int low, mid, high, result;

    low = -1;
    high = n;

    while (low + 1 < high) {

        mid = (low + high) / 2;

        if (v[mid] < x) {
          low = mid;
        } else {
          high = mid;
        }

    }

    if (n == high || v[high] != x) {
        result = -1;
    } else {
        result = high;
    }

    return result;
}

void print_search_result(int n, int index) {
    if (index < 0) {
        printf("Element %d not found.\n", n);
    } else {
        printf("Element %d found at index %d.\n", n, index);
    }
}

void print_search_benchmark(time_taken) {
    printf("binary_search() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
}

int main() {
    int i,
        index,
        n = 222,
        testdata[MAX_ELEMENT];
    clock_t time_taken;

    for (i = 0; i < MAX_ELEMENT; ++i) {
        testdata[i] = i;
    }

    for (i = 0, time_taken = clock(); i < 100000; ++i) {
        index = binary_search(n, testdata, MAX_ELEMENT);
    }

    print_search_result(n, index);

    time_taken = clock() - time_taken;

    print_search_benchmark(time_taken);

    for (i = 0, time_taken = clock(); i < 100000; ++i) {
        index = faster_binary_search(n, testdata, MAX_ELEMENT);
    }

    print_search_result(n, index);

    time_taken = clock() - time_taken;

    print_search_benchmark(time_taken);

    return 0;
}
