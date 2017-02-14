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

unsigned rotate_right(
    unsigned source_bits,
    int rotation_length
) {

    // e.g.
    // source_bits = 3
    // n = 2

    //  0  0  0  0  1  1 <- source_bits
    //  1  0  0  0  0  1
    //  1  1  0  0  0  0 <- output

    if (rotation_length == 0) {
        return source_bits;
    }

    if ((source_bits & 1) == 1) {
        // If source_bits ends in a 1, shift right, then create a mask (100...)
        // and | it against the (newly shifted) value of source_bits - pushing
        // a 1 onto the front and leaving the rest as-is.
        // I still don't understand why the cast (0U) is required.
        return rotate_right(source_bits >> 1 | ~(~0U >> 1), rotation_length - 1);
    } else {
        return rotate_right(source_bits >> 1, rotation_length - 1);
    }

}

int main(void) {
    int k;
    int x = 3;
    int n = 2;

    printf("--------------------------------------------------------------------------\n");

    printf("x: \n");
    printBits(sizeof(x), &x);
    printf("\n");

    k = rotate_right(x, n);
    printf("rotate_right(%u, %d) = %u\n\n", x, n, k);

    printf("k: \n");
    printBits(sizeof(k), &k);

    return 0;
}
