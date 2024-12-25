#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int teamSize = 0, brokenTeamSize = 0, surplusTeamSize = 0;
	scanf("%d %d %d", &teamSize, &brokenTeamSize, &surplusTeamSize);

	int* team = (int*)calloc(teamSize, sizeof(int));

	for (int i = 0; i < brokenTeamSize; i++) {
		int temp = 0;
		scanf("%d", &temp);
		team[temp - 1]--;
	}
	for (int i = 0; i < surplusTeamSize; i++) {
		int temp = 0;
		scanf("%d", &temp);
		team[temp - 1]++;
	}
	

	for (int i = 0; i < teamSize; i++) {
		if (team[i] == 1) {
			if (team[i - 1] == -1) { team[i - 1]++; }
			else if (team[i + 1] == -1) { team[i + 1]++; }
		}
	}

	int result = 0;
	for (int i = 0; i < teamSize; i++) {
		if (team[i] == -1) {
			result++;
		}
	}
	printf("%d", result);


	free(team);
	return 0;
}
