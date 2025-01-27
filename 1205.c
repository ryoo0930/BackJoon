#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int N, score, P;
	scanf("%d %d %d", &N, &score, &P);

	int* userScore = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &userScore[i]);

	int* rankScore = (int*)calloc(P, sizeof(int));
	if (N >= P) for (int i = 0; i < P; i++) rankScore[i] = userScore[i];
	else {
		int index = 0;
		for (index = 0; index < N; index++) rankScore[index] = userScore[index];
		for (index; index < P; index++) rankScore[index] = -1;
	}

	int ranking = -1;
	for (int i = 0; i < P; i++) {
		if (score >= rankScore[i]) {
			if (score != rankScore[P - 1]) {
				ranking = i + 1;
				break;
			}
		}
	}
	printf("%d", ranking);


	free(rankScore);
	free(userScore);
	return 0;
}
