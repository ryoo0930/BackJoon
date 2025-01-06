#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void maleFunction(int* arr, int size, int number);
void femaleFunction(int* arr, int size, int number);

int main(void) {
    int switchArrSize = 0;
    scanf("%d", &switchArrSize);

    int* switchArr = (int*)malloc(sizeof(int) * (switchArrSize));
    for (int i = 0; i < switchArrSize; i++) { scanf("%d", &switchArr[i]); }

    int testCase = 0;
    scanf("%d", &testCase);

    while (testCase--) {
        int gender = 0, number = 0;
        scanf("%d %d", &gender, &number);
        if (gender == 1) { maleFunction(switchArr, switchArrSize, number); }
        else if (gender == 2) { femaleFunction(switchArr, switchArrSize, number); }
    }

    for (int i = 0; i < switchArrSize; i++) {
        printf("%d ", switchArr[i]);
        if ((i + 1) % 20 == 0) { printf("\n"); }
    }

    free(switchArr);
    return 0;
}

void maleFunction(int* arr, int size, int number) {
    for (int i = 1; number * i <= size; i++) { arr[number * i - 1] = 1 - arr[number * i - 1]; }
}

void femaleFunction(int* arr, int size, int number) {
    int range = 1;
    arr[number - 1] = 1 - arr[number - 1]; // 받은 번호의 스위치 상태 먼저 변경

    while (1) {
        int left = number - range;
        int right = number + range;

        if (left < 1 || right > size) { break; }

        if (arr[left - 1] == arr[right - 1]) {
            arr[left - 1] = 1 - arr[left - 1];
            arr[right - 1] = 1 - arr[right - 1];
        }
        else { break; }
        range++;
    }
}
