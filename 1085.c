//1085
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int currentX = 0, currentY = 0, squareX = 0, squareY = 0;
	scanf("%d %d %d %d", &currentX, &currentY, &squareX, &squareY);
	int distance[4] = { 0 };
	distance[0] = currentX;
	distance[1] = currentY;
	distance[2] = squareX - currentX;
	distance[3] = squareY - currentY;

	qsort(distance, 4, sizeof(int), compare);
	printf("%d", distance[0]);

	return 0;
}

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	else { return 0; }
}