#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        int kindOfCandy = 0, minCandy = 0;
        scanf("%d %d", &kindOfCandy, &minCandy);
        int* arr = (int*)malloc(sizeof(int) * kindOfCandy);
        for (int i = 0; i < kindOfCandy; i++) { scanf("%d", &arr[i]); }

        int attendChild = 0;
        for (int i = 0; i < kindOfCandy; i++) {
            attendChild += arr[i] / minCandy;
        }
        printf("%d\n", attendChild);
        free(arr);
    }

    return 0;
}
