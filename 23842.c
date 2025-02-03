#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int number[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main() {
	int num = 0;
	scanf("%d", &num);
	num -= 4;
	
	int i, j, k;
	int flag = 0;
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100 - i; j++) {
			k = i + j;
			if (number[i / 10] + number[i % 10] + number[j / 10] + number[j % 10] + number[k / 10] + number[k % 10] == num) {
				printf("%d%d+%d%d=%d%d", i / 10, i % 10, j / 10, j % 10, k / 10, k % 10);
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (flag == 0) printf("impossible");
	return 0;
}
