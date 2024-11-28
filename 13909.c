//Aliquot & Multiple & Prime number 2 - 9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int count = 0;
    for (long long i = 1; i * i <= size; i++) {
        count++;
    }
    printf("%d", count);

    return 0;
}
