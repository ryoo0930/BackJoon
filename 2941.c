//2941
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[101];
	gets(string);

	int len = strlen(string);
	int alpha = 0;
	for (int i = 0; i < len; i++) {
		//c=, c-
		if (string[i] == 'c') {
			if (string[i + 1] == '=') {
				i++;
			}
			else if (string[i + 1] == '-') {
				i++;
			}
		}
		//dz=, d-
		else if (string[i] == 'd') {
			if (string[i + 1] == 'z') {
				if (string[i + 2] == '=') {
					i++;
					i++;
				}
			}
			if (string[i + 1] == '-') {
				i++;
			}
		}
		//lj
		else if (string[i] == 'l') {
			if (string[i + 1] == 'j') {
				i++;
			}
		}
		//nj
		else if (string[i] == 'n') {
			if (string[i + 1] == 'j') {
				i++;
			}
		}
		//s=
		else if (string[i] == 's') {
			if (string[i + 1] == '=') {
				i++;
			}
		}
		//z=
		else if (string[i] == 'z') {
			if (string[i + 1] == '=') {
				i++;
			}
		}
		alpha++;
	}

	printf("%d", alpha);

	return 0;
}