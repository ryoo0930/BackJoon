//30008
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int headcount = 0, size = 0;
    scanf("%d %d", &headcount, &size);
    int* subject = (int*)malloc(sizeof(int) * size);
    int* result = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) { 
        scanf("%d", &subject[i]);
        int temp = (subject[i] * 100) / headcount;
        if (temp <= 4) {
            result[i] = 1;
        }
        else if (temp <= 11) {
            result[i] = 2;
        }
        else if (temp <= 23) {
            result[i] = 3;
        }
        else if (temp <= 40) {
            result[i] = 4;
        }
        else if (temp <= 60) {
            result[i] = 5;
        }
        else if (temp <= 77) {
            result[i] = 6;
        }
        else if (temp <= 89) {
            result[i] = 7;
        }
        else if (temp <= 96) {
            result[i] = 8;
        }
        else if (temp <= 100) {
            result[i] = 9;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
