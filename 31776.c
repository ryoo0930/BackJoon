#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int teamSize = 0;
	scanf("%d", &teamSize);

	int** team = (int**)malloc(sizeof(int*) * teamSize);
	for (int i = 0; i < teamSize; i++) { team[i] = (int*)malloc(sizeof(int) * 3); }

	for (int i = 0; i < teamSize; i++) { for (int j = 0; j < 3; j++) { scanf("%d", &team[i][j]); } }

	int result = 0;
	for (int i = 0; i < teamSize; i++) {
		if (team[i][0] == -1) continue;

		if (team[i][1] == -1 && team[i][2] == -1) result++;
		else if (team[i][0] <= team[i][1] && team[i][2] == -1) result++;
		else if (team[i][0] <= team[i][1] && team[i][1] <= team[i][2]) result++;
	}
	printf("%d", result);


	for (int i = 0; i < teamSize; i++) free(team[i]);
	free(team);

	return 0;
}
