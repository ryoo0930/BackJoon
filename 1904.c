#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15746

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * (size + 1));
    arr[1] = 1;
    if (size >= 2) {
        arr[2] = 2;
        for (int i = 3; i <= size; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % MAXSIZE;
        }
    }
    printf("%d", arr[size]);
    free(arr);
    return 0;
}
