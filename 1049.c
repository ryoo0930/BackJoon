#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int needString = 0, brandSize = 0;
    scanf("%d %d", &needString, &brandSize);

    int* bundleArr = (int*)malloc(sizeof(int*) * brandSize);
    int* Arr = (int*)malloc(sizeof(int*) * brandSize);

    for (int i = 0; i < brandSize; i++) { scanf("%d %d", &bundleArr[i], &Arr[i]); }
    qsort(bundleArr, brandSize, sizeof(int), compare);
    qsort(Arr, brandSize, sizeof(int), compare);

    int result = 0;
    if (bundleArr[0] > (Arr[0] * 6)) {
        result += needString * Arr[0];
    }
    else {
        result += (needString / 6) * bundleArr[0];

        if (bundleArr[0] < Arr[0] * (needString % 6)) {
            result += bundleArr[0];
        }
        else {
            result += Arr[0] * (needString % 6);
        }
    }
    printf("%d", result);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
