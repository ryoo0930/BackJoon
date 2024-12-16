#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
}position;

typedef struct {
    int x;
    int y;
    int r;
}circle;

bool isIn(position dot, circle planet);

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        position start, end;
        scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);

        int planetSize;
        scanf("%d", &planetSize);
        circle* planet = (circle*)malloc(sizeof(circle) * planetSize);
        for (int i = 0; i < planetSize; i++) { scanf("%d %d %d", &planet[i].x, &planet[i].y, &planet[i].r); }

        int result = 0;
        for (int i = 0; i < planetSize; i++) {
            bool start_in = isIn(start, planet[i]);
            bool end_in = isIn(end, planet[i]);

            if (start_in != end_in) {
                result++;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}

bool isIn(position dot, circle planet) {
    int x = dot.x - planet.x;
    int y = dot.y - planet.y;
    return x* x + y * y > planet.r * planet.r ? true : false;
}
