#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int streamerSize = 0, changeTrendSize = 0;
    bool isVicious = false;
    scanf("%d %d", &streamerSize, &changeTrendSize);

    int** streamer = (int**)malloc(sizeof(int*) * streamerSize);
    for (int i = 0; i < streamerSize; i++) { streamer[i] = (int*)malloc(sizeof(int) * changeTrendSize); }
    for (int i = 0; i < streamerSize; i++) { for (int j = 0; j < changeTrendSize; j++) { scanf("%d ", &streamer[i][j]); } }

    for (int i = 1; i < streamerSize; i++) {
        int sum = 0;
        for (int j = 0; j < changeTrendSize; j++) {
            if (streamer[0][j] > streamer[i][j]) { sum += streamer[0][j] - streamer[i][j]; }
            else { sum += streamer[i][j] - streamer[0][j]; }
        }
        if (sum > 2000) { isVicious = true; }
    }

    isVicious ? printf("YES") : printf("NO");

    for (int i = 0; i < streamerSize; i++) { free(streamer[i]); }
    free(streamer);
    return 0;
}
