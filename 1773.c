#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool arr[2000001] = { false, };

int main()
{
	int size = 0, time = 0;
	scanf("%d %d", &size, &time);

	int temp = 0;
	for (int i = 0; i < size; i++) {
		scanf("%d", &temp);
		for (int j = temp; j <= time; j += temp) { arr[j] = true; }
	}

	int result = 0;
	for (int i = 0; i <= time; i++) { if (arr[i] == true) result++; }

	printf("%d", result);

	return 0;
}
