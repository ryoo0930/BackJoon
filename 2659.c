#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ClockNumberArr[10000] = { false, };
int MinClockNumber(int* arr);

int main(void) {
    int arr[4]; // 십자 카드 수
    for (int i = 0; i < 4; i++) { scanf("%d", &arr[i]); }

    int ClockNumber = MinClockNumber(arr);

    int TempArr[4] = { 1,1,1,0 }; // 첫번째로 작은 십자 카드 수 
    int result = 0;
    while(true) {
        TempArr[3]++;
        if (TempArr[3] == 10) { TempArr[2]++; TempArr[3] = 1; }
        if (TempArr[2] == 10) { TempArr[1]++; TempArr[2] = 1; }
        if (TempArr[1] == 10) { TempArr[0]++; TempArr[1] = 1; }

        int TempClockNumber = MinClockNumber(TempArr);
        //printf("TempClockNumber = %d\n", TempClockNumber);
        if (ClockNumberArr[TempClockNumber] == false) { ClockNumberArr[TempClockNumber] = true; result++; }
        if (TempClockNumber == ClockNumber) { break; }
    }

    printf("%d", result);


    return 0;
}

int MinClockNumber(int* arr) {
    int MinNumber = 10000;
    for (int i = 0; i < 4; i++) {
        int TempNumber = arr[i % 4] * 1000 + arr[(i + 1) % 4] * 100 + arr[(i + 2) % 4] * 10 + arr[(i + 3) % 4];
        if (TempNumber < MinNumber) { MinNumber = TempNumber; }
    }

    return MinNumber;
}
