//Aliquot & Multiple & Prime number 2 - 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAXSIZE 246913 //(123456 * 2) + 1

int prime[MAXSIZE] = { 0 };
void sieve();

int main(void) {
    sieve();
    int num;
    while (scanf("%d", &num) == 1 && num != 0) {
        int count = 0;
        for (int i = num + 1; i <= (2 * num); i++) {
            if (prime[i] != 1) {
                count++;
            }
        }
        printf("%d\n", count);
    }


    return 0;
}

void sieve() {
    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i <= sqrt(MAXSIZE); i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= MAXSIZE; j += i) {
                prime[j] = 1;
            }
        }
    }
}
