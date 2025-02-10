#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int testCase = 0;
    scanf("%d", &testCase);

    while (testCase--) {
        int K = 0;
        scanf("%d", &K);

        int result = 0;
        int current = 1;
        while (K--) {
            result += current;
            current = current * 2;
        }
        printf("%d\n", result);
    }

    return 0;
}
