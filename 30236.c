#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int arrSize = 0;
		scanf("%d", &arrSize);

		int* arr = (int*)malloc(sizeof(int) * arrSize);
		for (int i = 0; i < arrSize; i++) { scanf("%d", &arr[i]); }

		int answer = 0;
		for (int i = 0; i < arrSize; i++) {
			answer++;
			if (arr[i] == answer) answer++;
		}
		printf("%d\n", answer);

		free(arr);
	}
}
