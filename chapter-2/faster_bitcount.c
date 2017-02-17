#include <stdio.h>

// Kudos to @thomas-scrace for helping me wrap my head around this one!
// https://github.com/thomas-scrace/My-K-R-Exercise-Solutions/blob/master/c2/2.10/ex_2-9/bitcount_fast.c

// Q:
// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. (Use this observation to write a faster version of
// bitcount.)

// A: x - 1 (x') replaces the rightmost 1 in x with 0 and any/all 0s on
// its right with 1s. When x is &'d with x', the rightmost 1 in x (and any/all
// 1s on its right) becomes a 0 because the (individual column) logical
// operation is now 1 & 0/ 0 & 1.

// 64 32 16 08 04 02 01
//  1  0  0  0  0  0  1 | x
//  1  0  0  0  0  0  0 | x' = x - 1
//  1  0  0  0  0  0  0 | x & x'

int bitcount(unsigned bits) {
    int count;

    for (count = 0; bits != 0; (bits &= (bits - 1))) {
        count++;
    }

    return count;
}

int main() {
    int bits = 65; // 2
    int _bitcount = bitcount(bits);
    printf("bits in %d: %d\n", bits, _bitcount);
}
