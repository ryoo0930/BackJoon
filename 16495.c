#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char string[11];
	scanf("%s", string);

	long long result = 0;

	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		long long changeInt = string[i] - 'A' + 1;
		result += changeInt * (long long)pow(26, len - i - 1);
	}
	printf("%lld", result);


	return 0;
}
