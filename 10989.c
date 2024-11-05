//10989
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	scanf("%d", &size);
	int arr[10001] = { 0 };
	for (int i = 0; i < size; i++) {
		int num = 0;
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}