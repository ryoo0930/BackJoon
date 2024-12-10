#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int size = 0, maxWeight = 0;
    scanf("%d %d", &size, &maxWeight);

    int* arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
    
    int count = 1;
    int currentWeight = 0;
    for (int i = 0; i < size; i++) {
        if (currentWeight + arr[i] <= maxWeight) {
            currentWeight += arr[i];
        }
        else {
            count++;
            currentWeight = arr[i];
        }
    }

    if (size == 0) { // 책이 없을 때
        count = 0;
    }

    printf("%d", count);
    free(arr);

    return 0;
}
