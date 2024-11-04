//5522
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5] = { 0 };
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d ", &arr[i]);
		sum += arr[i];
	}
	printf("%d", sum);


	return 0;
}