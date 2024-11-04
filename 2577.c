//2577
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int arr[3] = { 0 };
	int sum = 1;
	for (int i = 0; i < 3; i++) {
		scanf("%d ", &arr[i]);
		sum = sum * arr[i];
	}

	char string[15] = { 0 };
	sprintf(string, "%d", sum);
	int len = strlen(string);
	int NUM[10] = { 0 };

	for (int i = 0; i < len; i++) {
		NUM[string[i] - 48]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", NUM[i]);
	}


	return 0;
}