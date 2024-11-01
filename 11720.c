//11720
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	scanf("%d", &size);
	while (getchar() != '\n');

	char* data = (char*)malloc(sizeof(char) * size);
	for (int i = 0; i < size; i++) {
		scanf("%1c", &data[i]);
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += data[i] - 48;
	}

	printf("%d", sum);
	return 0;
}