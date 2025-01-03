#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int addSize = 0, mulSize = 0;
    scanf("%d %d", &addSize, &mulSize);

    int* add = (int*)malloc(sizeof(int) * addSize);
    int* mul = (int*)malloc(sizeof(int) * mulSize);

    for (int i = 0; i < addSize; i++) { scanf("%d", &add[i]); }
    for (int i = 0; i < mulSize; i++) { scanf("%d", &mul[i]); }
    qsort(add, addSize, sizeof(int), compare);
    qsort(mul, mulSize, sizeof(int), compare);

    long long result = 0;
    for (int i = 0; i < addSize; i++) { result += add[i]; }
    for (int i = 0; i < mulSize; i++) {
        if (mul[i] == 0) { continue; }
        result *= mul[i];
    }
    printf("%lld", result);
    free(add);
    free(mul);
    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
