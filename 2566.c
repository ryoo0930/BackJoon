//2566
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[9][9];
	for (int i = 0; i < 9; i++) {
		scanf("%d %d %d %d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5], &arr[i][6], &arr[i][7], &arr[i][8]);
	}

	int checkw = 0, checkh = 0;
	int min = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (min <= arr[i][j]) {
				min = arr[i][j];
				checkw = i;
				checkh = j;
			}
		}
	}

	printf("%d\n", arr[checkw][checkh]);
	printf("%d %d\n", checkw + 1, checkh + 1);

	return 0;
}