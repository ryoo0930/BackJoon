//30802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N = 0;
	int T_size[6] = { 0 };
	int T = 0, P = 0;
	scanf("%d", &N);
	for (int i = 0; i < 6; i++) {
		scanf("%d ", &T_size[i]);
	}
	scanf("%d %d", &T, &P);

	int T_count = 0;
	int P_count = 0;

	for (int i = 0; i < 6; i++) {
		if (T_size[i] != 0) {
			if ((T_size[i] % T) == 0) {
				T_count += T_size[i] / T;
			}
			else {
				T_count += T_size[i] / T;
				T_count++;
			}
		}
	}
	printf("%d\n", T_count);
	printf("%d %d", N / P, N % P);

	return 0;
}