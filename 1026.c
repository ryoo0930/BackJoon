#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* arrA = (int*)malloc(sizeof(int) * size);
    int* arrB = (int*)malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++) { scanf("%d", &arrA[i]); }
    for (int i = 0; i < size; i++) { scanf("%d", &arrB[i]); }
    qsort(arrA, size, sizeof(int), compare);
    qsort(arrB, size, sizeof(int), compare);

    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arrA[i] * arrB[size - i - 1];
    }
    printf("%d", result);
    free(arrA);
    free(arrB);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
