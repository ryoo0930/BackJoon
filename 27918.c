#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int dalgu = 0, ponix = 0;
    char temp;
    int roundSize = 0;
    scanf("%d", &roundSize); getchar();

    int round = 0;
    for (round; round < roundSize; round++) {
        scanf("%c", &temp);
        temp == 'D' ? dalgu++ : ponix++;
        getchar();
        if (dalgu - ponix == 2 || dalgu - ponix == -2) break;
    }
    for (round += 1; round < roundSize; round++) {
        scanf("%c", &temp);
        getchar();
    }


    printf("%d:%d", dalgu, ponix);
    return 0;
}
