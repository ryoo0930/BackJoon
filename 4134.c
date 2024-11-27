//Aliquot & Multiple & Prime number 2 - 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool first_judge(long long num);
bool second_judge(long long num);
bool third_judge(long long num);

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        long long num = 0;
        scanf("%lld", &num);

        if (num <= 5) {
            if (num <= 2) {
                printf("2\n");
            }
            else if (num == 3) {
                printf("3\n");
            }
            else if (num <= 5) {
                printf("5\n");
            }
        }

        else {
            for (long long i = num;; i++) {
                if (first_judge(i) && second_judge(i) && third_judge(i)) {
                    printf("%lld\n", i);
                    break;
                }
            }
        }

    }
    return 0;
}

bool first_judge(long long num) {
    int judge = num % 10;
    if (judge == 1 || judge == 3 || judge == 7 || judge == 9) {
        return true;
    }
    else {
        return false;
    }
}

bool second_judge(long long num) {
    int judge = 0;
    while (num != 0) {
        judge += num % 10;
        num /= 10;
    }

    if ((judge % 3) != 0) {
        return true;
    }
    else {
        return false;
    }
}

bool third_judge(long long num) {
    long long i = 5;
    while ((i * i) <= num) {
        if ((num % i) == 0 || (num % (i + 2)) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}
