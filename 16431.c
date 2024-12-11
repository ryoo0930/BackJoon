#include <stdio.h>

typedef struct {
    int x;
    int y;
} position;

int abs(int num);
int bessieDistance(position bessie, position john);
int daisyDistance(position daisy, position john);

int main(void) {
    position bessie, daisy, john;
    scanf("%d %d", &bessie.x, &bessie.y);
    scanf("%d %d", &daisy.x, &daisy.y);
    scanf("%d %d", &john.x, &john.y);

    int bessieDis = bessieDistance(bessie, john);
    int daisyDis = daisyDistance(daisy, john);

    if (bessieDis > daisyDis) {
        printf("daisy\n");
    }
    else if (bessieDis < daisyDis) {
        printf("bessie\n");
    }
    else {
        printf("tie\n");
    }

    return 0;
}

int bessieDistance(position bessie, position john) {
    int dx = abs(bessie.x - john.x);
    int dy = abs(bessie.y - john.y);
    return dx > dy ? dx : dy;
}

int daisyDistance(position daisy, position john) {
    return abs(daisy.x - john.x) + abs(daisy.y - john.y);
}

int abs(int num) {
    return num < 0 ? -num : num;
}
