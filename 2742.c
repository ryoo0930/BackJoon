#include <stdio.h>
int main(void) {
    int num = 0;
    scanf("%d", &num);
    for (int i = num; i > 0; i--) { printf("%d\n", i); }

    return 0;
}
