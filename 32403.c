#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int bulbSize = 0, cycle = 0;
    scanf("%d %d", &bulbSize, &cycle);

    int* bulb = (int*)malloc(sizeof(int) * bulbSize);
    for (int i = 0; i < bulbSize; i++) { scanf("%d", &bulb[i]); }

    int FixCount = 0;
    for (int i = 0; i < bulbSize; i++) {
        if (bulb[i] > cycle) {
            FixCount += bulb[i] - cycle;
        }
        else {
            int CountP = 0, CountM = 0;
            int temp = bulb[i];
            while (cycle % temp != 0) {
                temp++;
                CountP++;
            }
            temp = bulb[i];
            while (cycle % temp != 0) {
                temp--;
                CountM++;
            }
            
            if (CountP > CountM) { FixCount += CountM; }
            else { FixCount += CountP; }
        }


    }

    printf("%d", FixCount);
    free(bulb);


    return 0;
}
