#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 25

bool visited[MAX_SIZE][MAX_SIZE] = { false, };
int map[MAX_SIZE][MAX_SIZE] = { 0, };
int result[MAX_SIZE]; int top = -1; int count = 0;
int size = 0;

void dfs(int x, int y);
int compare(const void* a, const void* b);

int main(void) {
    scanf("%d", &size);

    for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { scanf("%1d", &map[i][j]); } }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[i][j] == 1 && visited[i][j] == false) {
                count = 0;
                dfs(i, j);
                result[++top] = count;
            }
        }
    }
    top++;

    qsort(result, top, sizeof(int), compare);
    printf("%d\n", top);
    for (int i = 0; i < top; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    count++;

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < size && ny >= 0 && ny < size && map[nx][ny] == 1 && visited[nx][ny] == false) { dfs(nx, ny); }
    }
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
