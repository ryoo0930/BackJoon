#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N = 0, K = 0, P = 0;
    scanf("%d %d %d", &N, &K, &P);

    int arrSize = N * K;
    int* arr = malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) { scanf("%d", &arr[i]); }


    int Sellable = N;

    for (int i = 0; i < arrSize; i += K) {
        int NOTbread = 0;
        for (int j = i; j < i + K; j++) { if (arr[j] == 0) { NOTbread++; } }
        if (NOTbread >= P) { Sellable--; }
    }

    printf("%d", Sellable);
    free(arr);
    return 0;
}
