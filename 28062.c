#include <stdio.h>

int main(void) {
    int candySize = 0, maxCandy = 0;
    int minOdd = 1001;
    scanf("%d", &candySize);

    for (int i = 0; i < candySize; i++) {
        int temp = 0;
        scanf("%d", &temp);
        maxCandy += temp;

        if ((temp % 2) == 1 && temp < minOdd) { minOdd = temp; }
    }

    if ((maxCandy % 2) == 1) { maxCandy -= minOdd; }
    printf("%d", (maxCandy % 2) == 0 ? maxCandy : 0);
    return 0;
}
