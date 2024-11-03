//31403
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[3] = { 0 };
	int count = 1;
	for(int i = 0; i < 3; i++){
		scanf("%d ", &arr[i]);
	}

	int n = arr[1];
	while (n != 0) {
		n = n / 10;
		count = count * 10;
	}

	printf("%d\n", arr[0] + arr[1] - arr[2]);
	printf("%d", (arr[0] * count) + arr[1] - arr[2]);
	return 0;
}