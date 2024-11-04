//10988
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void) {
	while (1) {
		int num = 0;
		scanf("%d", &num);
		getchar();
		if (num == 0) {
			break;
		}
		char string[100000] = { 0 };
		sprintf(string, "%d", num);

		int checkSame = 0;
		for (int i = 0; i < strlen(string); i++) {
			if (string[i] != string[strlen(string) - 1 - i]) {
				checkSame++;
				break;
			}
		}
		if (checkSame == 0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	
	return 0;
}