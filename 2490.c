#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int Yutjak[3][4];
    for (int i = 0; i < 3; i++) { for (int j = 0; j < 4; j++) { scanf("%d", &Yutjak[i][j]); } }
    for (int i = 0; i < 3; i++) {
        int bae = 0;
        for (int j = 0; j < 4; j++) { if (Yutjak[i][j] == 0) { bae++; } }

        if (bae == 1) { printf("A\n"); }
        else if (bae == 2) { printf("B\n"); }
        else if (bae == 3) { printf("C\n"); }
        else if (bae == 4) { printf("D\n"); }
        else { printf("E\n"); }
    }

    return 0;
}
