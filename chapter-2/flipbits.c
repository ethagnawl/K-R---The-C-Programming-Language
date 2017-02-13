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

unsigned flip_n_bits_from_p(
    unsigned source_bits,
    int mask_offset,
    int mask_length
) {

    // e.g.
    // source_bits = 17
    // p = 2
    // n = 2

    //  0  0  0  0  1  1 <- flip mask of length n
    //  0  0  1  1  0  0 <- shift to p
    //  0  1  0  0  0  1 <- source_bits
    //                   <- ^
    //  0  0  1  1  0  0 <- mask
    //  0  1  1  1  0  1 <- output

    int mask =  ~(~0 << mask_length) << mask_offset;

    return source_bits ^ mask;
}

int main(void) {
    int k;
    int x = 17;
    int p = 2;
    int n = 2;

    printf("--------------------------------------------------------------------------\n");

    printf("x: \n");
    printBits(sizeof(x), &x);
    printf("\n");

    k = flip_n_bits_from_p(x, p, n);
    printf("flip_n_bits_from_p(%u, %d, %d) = %u\n\n", x, p, n, k);

    printf("k: \n");
    printBits(sizeof(k), &k);

    return 0;
}
