#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int card[10] = { 0, };

	int room = 0;
	scanf("%d", &room);
	
	while (room != 0) {
		int number = room % 10;
		room /= 10;
		card[number]++;
	}

	int card_6 = card[6] + card[9];
	card[6] = card_6 / 2;
	if (card_6 % 2 == 1) { card[6]++; }

	qsort(card, 9, sizeof(int), compare);
	printf("%d", card[8]);

	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
