//Set & Map 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int binsearch(int* data, int size, int key);

int main(void) {
    int sizeA = 0, sizeB = 0;
    scanf("%d %d", &sizeA, &sizeB);
    int* arrA = (int*)malloc(sizeof(int) * sizeA);
    int* arrB = (int*)malloc(sizeof(int) * sizeB);

    for (int i = 0; i < sizeA; i++) { scanf("%d", &arrA[i]); }
    for (int i = 0; i < sizeB; i++) { scanf("%d", &arrB[i]); }

    qsort(arrA, sizeA, sizeof(int), compare);
    qsort(arrB, sizeB, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < sizeA; i++) {
        if (binsearch(arrB, sizeB, arrA[i]) == -1) {
            count++;
        }
    }
    for (int i = 0; i < sizeB; i++) {
        if (binsearch(arrA, sizeA, arrB[i]) == -1) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int binsearch(int* data, int size, int key) {
    int high, low, mid;
    low = 0;
    high = size - 1;
    int index = -1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (data[mid] == key) {
            index = 1;
            break;
        }
        else if (data[mid] > key) {
            high = mid - 1;
        }
        else if (data[mid] < key) {
            low = mid + 1;
        }
    }
    return index;
}
