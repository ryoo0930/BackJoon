//14215
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int sides[3];
	for (int i = 0; i < 3; i++) { scanf("%d", &sides[i]); }

	qsort(sides, 3, sizeof(int), compare);

	while (sides[0] + sides[1] <= sides[2]) {
		sides[2]--;
	}

	int result = 0;
	for (int i = 0; i < 3; i++) { result += sides[i]; }
	printf("%d", result);
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}