//11723
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int arr[21] = { 0 };
	int testCase = 0;
	scanf("%d", &testCase);
	getchar();
	for (int i = 0; i < testCase; i++) {
		char* calculation[7] = { 0 };
		int num = 0;
		scanf("%s %d", &calculation, &num);
		
		if (strcmp(calculation, "add") == 0) {
			arr[num] = 1;
		}
		else if (strcmp(calculation, "remove") == 0) {
			arr[num] = 0;
		}
		else if (strcmp(calculation, "check") == 0) {
			printf("%d\n", arr[num]);
		}
		else if (strcmp(calculation, "toggle") == 0) {
			if (arr[num] == 1) {
				arr[num] = 0;
			}
			else {
				arr[num] = 1;
			}
		}
		else if (strcmp(calculation, "all") == 0) {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (strcmp(calculation, "empty") == 0) {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}

	return 0;
}