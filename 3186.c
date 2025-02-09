#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int K, L, N;
    scanf("%d %d %d", &K, &L, &N);

    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) scanf("%1d", &arr[i]);

    bool used = false;
    int use = 0, n_use = 0, i = 0;
    bool flag = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] == 1) {
            use++;
            n_use = 0;
        }
        else if (arr[i] == 0) {
            n_use++;
            use = 0;
        }
        
        if (use == K) used = true;
        if (n_use == L && used) {
            printf("%d\n", i + 1);
            used = false;
            flag = 1;
        }
    }

    while (used == true) {
        n_use++;
        if (n_use == L) {
            printf("%d\n", i + 1);
            used = false;
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 0) {
        printf("NIKAD\n");
    }


    free(arr);
    return 0;
}
