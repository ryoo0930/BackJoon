#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int classSize = 0;
    scanf("%d", &classSize);

    int* class = (int*)malloc(sizeof(int) * classSize);
    for (int i = 0; i < classSize; i++) { scanf("%d", &class[i]); }

    int generalManager, subManager;
    scanf("%d %d", &generalManager, &subManager);

    long long needPeople = 0;
    for (int i = 0; i < classSize; i++) {
        //generalManager
        needPeople += 1;
        class[i] -= generalManager;

        //subManager;
        if (class[i] > 0) {
            needPeople += class[i] / subManager;
            if (class[i] % subManager != 0) { needPeople++; }
        }
    }

    printf("%lld", needPeople);

    free(class);
    return 0;
}
