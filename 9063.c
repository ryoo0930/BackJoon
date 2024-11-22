//9063
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct pos {
	int x;
	int y;
};

int compareX(struct pos* a, struct pos* b);
int compareY(struct pos* a, struct pos* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	struct pos* p = (struct pos*)calloc(testCase, sizeof(struct pos));

	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	qsort(p, testCase, sizeof(struct pos), compareX);
	int resultX = p[testCase - 1].x - p[0].x;
	qsort(p, testCase, sizeof(struct pos), compareY);
	int resultY = p[testCase - 1].y - p[0].y;

	printf("%d", resultX * resultY);

	free(p);
	return 0;
}

int compareX(struct pos* a, struct pos* b) {
	if (a->x > b->x) { return 1; }
	else if (a->x < b->x) { return -1; }
	else { return 0; }
}

int compareY(struct pos* a, struct pos* b) {
	if (a->y > b->y) { return 1; }
	else if (a->y < b->y) { return -1; }
	else { return 0; }
}