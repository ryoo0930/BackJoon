//5073
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool checkSide(int* sides);
int compare(const void* a, const void* b);


int main(void) {
	while (true) {
		int sides[3] = { 0 };
		for (int i = 0; i < 3; i++) { scanf("%d", &sides[i]); }

		if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0) { break; } // 종료 조건.
		qsort(sides, 3, sizeof(int), compare);

		if (checkSide(sides) == false) {
			printf("Invalid\n");
		}
		else if (sides[0] == sides[1] && sides[1] == sides[2]) {
			printf("Equilateral\n");
		}
		else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[2] == sides[0]) {
			printf("Isosceles\n");
		}
		else {
			printf("Scalene\n");
		}
	}

	return 0;
}

bool checkSide(int* sides) {
	if (sides[2] < sides[0] + sides[1]) { return true; }
	else { return false; }
}

int compare(const void* a, const void* b) {
	return (*(int *)a - *(int *)b);
}