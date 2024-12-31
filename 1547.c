#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    int arr[3] = { 1, 0, 0 };
    for (int i = 0; i < testCase; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        swap(&arr[a - 1], &arr[b - 1]);
    }
    for (int i = 0; i < 3; i++) {
        if (arr[i] == 1) { printf("%d", i + 1); }
    }

    return 0;
}

void swap(int* a, int* b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}
