#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void maleFunction(int* arr, int size, int number);
void femaleFunction(int* arr, int size, int number);

int main(void) {
    int switchArrSize = 0;
    scanf("%d", &switchArrSize);

    int* switchArr = (int*)malloc(sizeof(int) * (switchArrSize + 1));
    for (int i = 1; i <= switchArrSize; i++) { scanf("%d", &switchArr[i]); }

    int testCase = 0;
    scanf("%d", &testCase);

    while (testCase--) {
        int gender = 0, number = 0;
        scanf("%d %d", &gender, &number);
        if (gender == 1) { maleFunction(switchArr, switchArrSize, number); }
        else if (gender == 2) { femaleFunction(switchArr, switchArrSize, number); }
    }

    for (int i = 1, index = 0; i <= switchArrSize; i++, index++) {
        printf("%d ", switchArr[i]);
        if (i % 20 == 0) { printf("\n"); }
    }

    free(switchArr);
    return 0;
}

void maleFunction(int* arr, int size, int number) {
    for (int i = 1; number * i <= size; i++) {
        arr[number * i] = 1 - arr[number * i];
    }
}

void femaleFunction(int* arr, int size, int number) {
    arr[number] = 1 - arr[number];

    int range = 1;
    while (1) {
        if (number - range == 0 || number + range == size + 1) { break; }
        if (arr[number - range] == arr[number + range]) {
            arr[number - range] = 1 - arr[number - range];
            arr[number + range] = 1 - arr[number + range];
        }
        else { break; }
        range++;
    }
}
