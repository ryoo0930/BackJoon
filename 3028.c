//3028
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(void) {
    int arr[3] = { 1, 0, 0 };
    char step[51];
    scanf("%s", &step);

    int len = strlen(step);
    for (int i = 0; i < len; i++) {
        if (step[i] == 'A') {
            swap(&arr[0], &arr[1]);
        }
        else if (step[i] == 'B') {
            swap(&arr[1], &arr[2]);
        }
        else if (step[i] == 'C') {
            swap(&arr[2], &arr[0]);
        }
    }

    for (int i = 0; i < 3; i++) { if (arr[i] == 1) printf("%d", i + 1); }

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
