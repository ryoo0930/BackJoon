#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkFunction(char* str1, char* str2);

int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		char originString[1001];
		char strfryString[1001];
		scanf("%s %s", originString, strfryString);
		checkFunction(originString, strfryString);
	}

	return 0;
}

void checkFunction(char* str1, char* str2){
	int len1 = strlen(str1), len2 = strlen(str2);
	int arr1[26] = { 0, }, arr2[26] = { 0, };

	for (int i = 0; i < len1; i++) { arr1[str1[i] - 'a']++; }
	for (int i = 0; i < len2; i++) { arr2[str2[i] - 'a']++; }

	for (int i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i]) { printf("Impossible\n"); return; }
	}
	printf("Possible\n");
}
