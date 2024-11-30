//5724
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int size = NULL;
    
    while (scanf("%d", &size) == 1 && size != 0) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += (size - i) * (size - i);
        }
        printf("%d\n", result);
    }


    return 0;
}
