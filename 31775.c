#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char string[3][21];
	for (int i = 0; i < 3; i++) scanf("%s", &string[i]);

	bool l = false, k = false, p = false;
	for (int i = 0; i < 3; i++) {
		if (string[i][0] == 'l') l = true;
		else if (string[i][0] == 'k') k = true;
		else if (string[i][0] == 'p') p = true;
	}

	if (l && k && p) printf("GLOBAL");
	else printf("PONIX");

	return 0;
}
