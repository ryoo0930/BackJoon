#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void reverseArr(int* arr, int start, int end);

int main(void) {
    int arr[21];
    for (int i = 0; i <= 20; i++) { arr[i] = i; }

    for (int testCase = 1; testCase <= 10; testCase++) {
        int start = 0, end = 0;
        scanf("%d %d", &start, &end);
        reverseArr(arr, start, end);
    }


    for (int i = 1; i <= 20; i++) { printf("%d ", arr[i]); }
    return 0;
}

void reverseArr(int* arr, int start, int end) {
    int size = end - start + 1;
    int* newArr = (int*)malloc(sizeof(int) * size);
    for (int index = 0; index < size; index++) { newArr[index] = arr[end--]; }
    for (int index = 0; index < size; index++) { arr[start++] = newArr[index]; }
    free(newArr);
}
