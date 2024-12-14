#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int index;
    int value;
}item;

int compare(const void* a, const void* b);

int main(void) {
    int arrSize = 0;
    scanf("%d", &arrSize);

    item* arr = (item*)malloc(sizeof(item) * arrSize);
    for (int i = 0; i < arrSize; i++) { scanf("%d", &arr[i].value); arr[i].index = i; }
    qsort(arr, arrSize, sizeof(item), compare);

    int* arrP = (int*)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) { arrP[arr[i].index] = i; }
    for (int i = 0; i < arrSize; i++) { printf("%d ", arrP[i]); }

    free(arrP);
    free(arr);

    return 0;
}

int compare(const void* a, const void* b) {
    item* iA = (item*)a;
    item* iB = (item*)b;

    if (iA->value > iB->value) { return 1; }
    if (iA->value < iB->value) { return -1; }
    else { return iA->index - iB->index; }
}
