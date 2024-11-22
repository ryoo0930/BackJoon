//3009
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct pos {
	int x;
	int y;
};

int main(void) {
	struct pos p[4];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	if (p[0].x == p[1].x) {
		p[3].x = p[2].x;
	}
	else if (p[0].x == p[2].x) {
		p[3].x = p[1].x;
	}
	else if (p[1].x == p[2].x) {
		p[3].x = p[0].x;
	}

	if (p[0].y == p[1].y) {
		p[3].y = p[2].y;
	}
	else if (p[0].y == p[2].y) {
		p[3].y = p[1].y;
	}
	else if (p[1].y == p[2].y) {
		p[3].y = p[0].y;
	}

	printf("%d %d", p[3].x, p[3].y);
	return 0;
}