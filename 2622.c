#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool checkTriangle(int a, int b, int c);

int main(void) {
	int sides = 0;
	scanf("%d", &sides);
	
	int count = 0;
	for (int i = 1; i <= sides / 3; i++) {
		for (int j = i; j <= (sides - i) / 2; j++) {
			int k = sides - i - j;
			if (checkTriangle(i, j, k)) { count++; }
		}
	}
	printf("%d", count);

}

bool checkTriangle(int a, int b, int c) {
	return a + b > c ? true : false;
}
