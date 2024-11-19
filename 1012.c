//1012
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** field, bool** visited, int height, int width, int x, int y);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	for (int T = 0; T < testCase; T++) {
		int width, height, size;
		scanf("%d %d %d", &width, &height, &size);

		int** field = (int**)calloc(height, sizeof(int*));
		bool** visited = (bool**)calloc(height, sizeof(bool*));
		for (int i = 0; i < height; i++) {
			field[i] = (int*)calloc(width, sizeof(int));
			visited[i] = (bool*)calloc(width, sizeof(bool));
		}

		for (int i = 0; i < size; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			field[y][x] = 1;
		}

		int result = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (field[i][j] == 1 && visited[i][j] == false) {
					dfs(field, visited, height, width, j, i);
					result++;
				}
			}
		}

		printf("%d\n", result);

		for (int i = 0; i < height; i++) {
			free(field[i]);
			free(visited[i]);
		}
		free(field);
		free(visited);
	}


	return 0;
}

void dfs(int** field, bool** visited, int height, int width, int x, int y) {
	int aroundX[4] = { -1, 1, 0, 0 };
	int aroundY[4] = { 0, 0, -1, 1 };
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nearX = x + aroundX[i];
		int nearY = y + aroundY[i];

		if (nearX >= 0 && nearX < width && nearY >= 0 && nearY < height && field[nearY][nearX] == 1 && visited[nearY][nearX] == false) {
			dfs(field, visited, height, width, nearX, nearY);
		}
	}
}