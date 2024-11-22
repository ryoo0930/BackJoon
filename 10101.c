//10101
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool degree180(int* degree);

int main(void) {
	int degree[3] = { 0 };
	for (int i = 0; i < 3; i++) { scanf("%d", &degree[i]); }

	if (degree[0] == 60 && degree[1] == 60 && degree[2] == 60) {
		printf("Equilateral");
	}
	else if (degree180(degree) == false) {
		printf("Error");
	}
	else if (degree180(degree) == true && degree[0] == degree[1] || degree180(degree) == true && degree[1] == degree[2] || degree180(degree) == true && degree[2] == degree[0]) {
		printf("Isosceles");
	}
	else {
		printf("Scalene");
	}


	return 0;
}

bool degree180(int* degree) {
	int result = 0;
	for (int i = 0; i < 3; i++) {
		result += degree[i];
	}

	if (result == 180) { return true; }
	else { return false; }
}