//28702 FizzBuzz
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FizzBuzz(int* arr);
int main(void) {
	char string[3][9] = { 0 };
	int arr[4] = { 0 };

	for (int i = 0; i < 3; i++) {
		gets(string[i]);
	}
	
	for (int i = 0; i < 3; i++) {
		arr[i] = atoi(string[i]);
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] != 0) {
			arr[3] = arr[i] + 3 - i;
			break;
		}
	}

	//arr[3] = result (but is not check FizzBuzz
	FizzBuzz(arr);




	return 0;
}

void FizzBuzz(int* arr) {
	int checkNUM = arr[3];
	int check3 = checkNUM % 3;
	int check5 = checkNUM % 5;

	if (check3 == 0 && check5 == 0) {
		printf("FizzBuzz");
	}
	else if (check3 == 0) {
		printf("Fizz");
	}
	else if (check5 == 0) {
		printf("Buzz");
	}
	else {
		printf("%d", checkNUM);
	}

}