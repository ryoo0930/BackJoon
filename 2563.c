//2563
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[100][100] = { 0 };
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int width = 0, height = 0;
		scanf("%d %d", &width, &height);
		for (int j = width; j < width + 10; j++) {
			for (int k = height; k < height + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}

	int area = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				area++;
			}
		}
	}
	printf("%d", area);


	return 0;
}