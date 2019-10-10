#include <stdint.h>

/**
 * Fast log2(x)-algorithm using binary search.
 * Time complexity: O(log n) where n is number of bits.
 */
int fast_log2(uint32_t x) {
    int result = 0;
    uint32_t m[] = { 0xFFFF0000, 0xFF00, 0xF0, 0xC, 0x2 };
    int s[] = { 16, 8, 4, 2, 1 };
    for (int i = 0; i < 5; i++) {
        if (x & m[i]) {
            result |= s[i];
            x >>= s[i];
        }
    }
    return result;
}
