//Aliquot & Multiple & Prime number 2 - 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000000
int arr[MAXSIZE] = { 0 };

void sieve();

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    sieve();

    for (int t = 0; t < testCase; t++) {
        int num = 0;
        scanf("%d", &num);

        int count = 0;
        for (int i = 2; i <= num / 2; i++) {
            if (arr[i] == 0 && arr[num - i] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

void sieve() {
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= 1000; i++) {
        if (arr[i] == 0) {
            for (int j = (i + i); j <= 1000000; j += i) {
                arr[j] = 1;
            }
        }
    }

}
