//1094
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int size = 0;
	scanf("%d", &size);

	int count = 0;

	for (int i = 8; i >= 0; i--) {
		if (size & (1 << i)) {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}