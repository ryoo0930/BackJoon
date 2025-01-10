#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int arr1[26] = { 0, }, arr2[26] = { 0, };
	char string1[1001], string2[1001];

	scanf("%s", string1);
	scanf("%s", string2);

	int len1 = strlen(string1), len2 = strlen(string2);

	for (int i = 0; i < len1; i++) { arr1[string1[i] - 'a']++; }
	for (int i = 0; i < len2; i++) { arr2[string2[i] - 'a']++; }

	int result = 0;
	for (int i = 0; i < 26; i++) {
		if (arr1[i] > arr2[i]) { result += arr1[i] - arr2[i]; }
		else if (arr2[i] > arr1[i]) { result += arr2[i] - arr1[i]; }
	}

	printf("%d", result);

	return 0;
}
