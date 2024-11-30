//13866
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int arr[4];
    for (int i = 0; i < 4; i++) { scanf("%d", &arr[i]); }
    int team1 = arr[0] + arr[3];
    int team2 = arr[1] + arr[2];
    
    int result = team1 - team2;
    if (result >= 0) {
        printf("%d", result);
    }
    else {
        printf("%d", 0 - result);
    }


    return 0;
}
