#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(void) {
    int arrSize = 0, count = 0;
    scanf("%d %d", &arrSize, &count);

    int* arr = (int*)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) { scanf("%d", &arr[i]); }

    //Selection sort
    int currentCount = 0;
    for (int i = arrSize - 1; i > 0; i--) {
        int current = i, target = i;
        int MaxNum = arr[i];
        for (int j = i; j >= 0; j--) { if (arr[j] > MaxNum) { target = j; MaxNum = arr[j]; } }

        if (current != target) { swap(&arr[current], &arr[target]); currentCount++; }
        if (currentCount == count) { printf("%d %d", arr[target], arr[current]); break; }
    }

    if (currentCount < count) { printf("-1"); }

    free(arr);
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
