#include <stdio.h>
#include <string.h>

void heapsort(int* a, int len);

int main(void) {
    int arr[] = { 22, 1, 98, 30, 23, 6, 3, 4, 7, 5, 45, 54, 1, 2, 15 };
    size_t size = sizeof(arr)/sizeof(int);
    int cpy[size];

    puts("Heapsort:");
    memcpy(cpy, arr, sizeof(arr));
    heapsort(cpy, size);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", cpy[i]);
    }
    puts("");
}