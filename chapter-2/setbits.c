#include <stdio.h>

// http://stackoverflow.com/a/3974138/382982
void printBits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int bitmask = ~(~0 << n);   // used to query ns from y
    int shiftwidth = p + 1 - n;

    //      32 16  8  4  2  1
    //  ---------------------
    //  x =  0  1  0  0  0  1 (17)
    //  y =  1  0  1  0  1  0 (42)
    //  ---------------------
    //  l =  0  1  0  0  0  1
    //  r =  0  0  0  1  0  0
    //  $ =  0  1  0  1  0  1

    int left = x & ((~0 << (p + 1)) | (~(~0 << shiftwidth)));
    int right = (y & bitmask) << shiftwidth;

    return left | right;
}

int main(void) {
    int k;
    int x = 17;
    int p = 3;
    int n = 3;
    int y = 42;

    printf("--------------------------------------------------------------------------\n");

    printf("x: \n");
    printBits(sizeof(x), &x);
    printf("\n");

    printf("y: \n");
    printBits(sizeof(y), &y);
    printf("\n");

    k = setbits(x, p, n, y);
    printf("setbits(%u, %d, %d, %u) = %u\n\n", x, p, n, y, k);

    printf("k: \n");
    printBits(sizeof(k), &k);

    return 0;
}
