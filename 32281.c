#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long sum(long long num);


int main() {
    int arrSize = 0;
    scanf("%d", &arrSize);

    char* arr = (char*)malloc(sizeof(char) * (arrSize + 1));
    scanf("%s", arr);

    long long result = 0;
    long long num = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == '0') {
            result += sum(num);
            num = 0;
        }
        else num++;
    }
    if (arr[arrSize - 1] == '1') result += sum(num);

    printf("%lld", result);

    free(arr);
    return 0;
}

long long sum(long long num){
    long long result = 0;
    result = (num * (num + 1)) / 2;
    return result;
}
