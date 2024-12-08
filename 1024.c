#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int sum = 0, size = 0;
	scanf("%d %d", &sum, &size);

	int length = size;
	for (length; length <= 100; length++) {
		int offset = (length * (length - 1)) / 2;
		if (sum < offset) continue;

		int x = (sum - offset) / length;
		if (x >= 0 && (sum - offset) % length == 0) {
			for (int i = 0; i < length; i++) {
				printf("%d ", x + i);
			}
			break;
		}
	}
	if (length == 101) {
		printf("-1");
	}

	return 0;
}
