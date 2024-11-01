//10813
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int basketSize = 0;
	int changeCount = 0;
	scanf("%d %d", &basketSize, &changeCount);
	int* basket = (int*)malloc(sizeof(int) * basketSize);

	for (int i = 0; i < basketSize; i++) {
		basket[i] = i + 1;
	}
	
	int i = 0, j = 0;
	for (int cnt = 0; cnt < changeCount; cnt++) {
		scanf("%d %d", &i, &j);

		int temp = basket[i - 1];
		basket[i - 1] = basket[j - 1];
		basket[j - 1] = temp;
	}
	

	for (int i = 0; i < basketSize; i++) {
		printf("%d ", basket[i]);
	}

	free(basket);
	return 0;
}