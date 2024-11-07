//11651
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct dots {
	int x;
	int y;
};

int compare(struct dots* a, struct dots* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	struct dots* d = (struct dots*)malloc(sizeof(struct dots) * testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &d[i].x, &d[i].y);
	}

	qsort(d, testCase, sizeof(struct dots), compare);
	for (int i = 0; i < testCase; i++) {
		printf("%d %d\n", d[i].x, d[i].y);
	}

	return 0;
}

int compare(struct dots* a, struct dots* b) {
	if (a->y > b->y) { return 1; }
	else if (a->y < b->y) { return -1; }
	else { return a->x - b->x; }
}