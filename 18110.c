//18110
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

compare(const void* a, const void* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	if (testCase == 0) {
		printf("0");
	}
	else {
		int* arr = (int*)calloc(testCase, sizeof(int));
		for (int i = 0; i < testCase; i++) {
			scanf("%d ", &arr[i]);
		}
		qsort(arr, testCase, sizeof(int), compare); // 정렬

		int deleteP = 0;
		deleteP = (int)round((float)testCase * 0.15); // 15%에 해당하는 사람 수 구하기. (int 형)

		float sum = 0;
		float check = 0;
		for (int i = deleteP; i < testCase - deleteP; i++) {
			sum += arr[i];
			check++;
		}
		float result = sum / check;


		printf("%d", (int)round(result));
		free(arr);
	}
	
	return 0;
}

compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	else { return 0; }
}