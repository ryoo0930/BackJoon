#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int candidate, voter;
		scanf("%d %d", &candidate, &voter);

		int** arr = (int**)malloc(sizeof(int*) * voter);
		for (int i = 0; i < voter; i++) { arr[i] = (int*)malloc(sizeof(int) * candidate); }
		for (int i = 0; i < voter; i++) { for (int j = 0; j < candidate; j++) { scanf("%d", &arr[i][j]); } }

		int* vote_count = (int*)calloc(candidate + 1, sizeof(int)); // 1번 ~ candidate번 index로 접근. // 0번은 그냥 0;

		// 1회차 투표.
		int majority = (voter / 2) + 1, winner = -1;
		for (int i = 0; i < voter; i++) { vote_count[arr[i][0]]++; }

		
		for (int i = 1; i <= candidate; i++) {
			if (vote_count[i] >= majority) {
				winner = i; break;
			}
		}

		if (winner != -1) { // 1회차 투표에서 끝날 경우.
			printf("%d 1\n", winner);

			free(vote_count);
			for (int i = 0; i < voter; i++) free(arr[i]);
			free(arr);

			continue;
		}
		
		// 2회차 투표.
		int first = 0, second = 0; 
		int first_vote = 0, second_vote = 0;
		for (int i = 1; i <= candidate; i++) { // 상위 2명 계산.
			if (vote_count[i] > first_vote) {
				second = first;
				second_vote = first_vote;
				first = i;
				first_vote = vote_count[i];
			}
			else if (vote_count[i] > second_vote) {
				second = i;
				second_vote = vote_count[i];
			}
		}

		int second_vote_count[2] = { 0, 0 };
		for (int i = 0; i < voter; i++) {
			for (int j = 0; j < candidate; j++) {
				if (arr[i][j] == first) {
					second_vote_count[0]++; break;
				}
				else if (arr[i][j] == second) {
					second_vote_count[1]++; break;
				}
			}
		}

		second_vote_count[0] > second_vote_count[1] ? printf("%d 2\n", first) : printf("%d 2\n", second);

		free(vote_count);
		for (int i = 0; i < voter; i++) free(arr[i]);
		free(arr);
	}

	return 0;
}
