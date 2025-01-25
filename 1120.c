#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string1[51], string2[51];
	scanf("%s %s", string1, string2);

	int len1 = strlen(string1), len2 = strlen(string2);

	int min = 100;
	for (int start = 0; start <= len2 - len1; start++) {
		int different = 0;;
		for (int i = 0; i < len1; i++) {
			if (string1[i] != string2[i + start]) {
				different++;
			}
		}
		if (different < min) min = different;
	}

	printf("%d", min);

	return 0;
}
