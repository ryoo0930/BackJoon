#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* call = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) { scanf("%d", &call[i]); }

    int Yungsik = 0, Minsik = 0;
    for (int i = 0; i < size; i++) {
        Yungsik += ((call[i] / 30) + 1) * 10;
        Minsik += ((call[i] / 60) + 1) * 15;
    }

    if (Yungsik == Minsik) { printf("Y M %d", Yungsik); }
    else if (Yungsik > Minsik) { printf("M %d", Minsik); }
    else { printf("Y %d", Yungsik); }


    free(call);
    return 0;
}
