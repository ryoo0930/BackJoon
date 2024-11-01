//10811
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int basketSize = 0;
	int changeBasket = 0;

	scanf("%d %d", &basketSize, &changeBasket);
	int* basket = (int*)malloc(sizeof(int) * basketSize);
	int* tempBasket = (int*)malloc(sizeof(int) * basketSize);
	for (int i = 0; i < basketSize; i++) {
		basket[i] = i + 1;
		tempBasket[i] = i + 1;
	}

	for (int i = 0; i < changeBasket; i++) {
		int j = 0, k = 0;
		scanf("%d %d", &j, &k);
		int var = k - 1;
		int var2 = j - 1;
		for (j; j <= k; j++) {
			tempBasket[var] = basket[var2];
			var--;
			var2++;
		}
		for (int l = 0; l < basketSize; l++) {
			basket[l] = tempBasket[l];
		}
	}
	
	for (int i = 0; i < basketSize; i++) {
		printf("%d ", basket[i]);
	}

	free(tempBasket);
	free(basket);
	return 0;
}