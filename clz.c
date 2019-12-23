#include <stdint.h>

/**
 * Fast "Count leading zeros" algorithm using binary search.
 * Time complexity: O(log n) where n is number of bits.
 */
int fast_clz(uint32_t x) {
    if (x == 0) return 32;
    int result = 0;
    uint32_t m[] = { 
        0xFFFF0000,
        0xFF000000,
        0xF0000000,
        0xC0000000,
        0x80000000
    };
    int s[] = { 16, 8, 4, 2, 1 };
    for (int i = 0; i < 5; i++) {
        if ((x & m[i]) == 0) {
            result |= s[i];
            x <<= s[i];
        }
    }
    return result;
}
