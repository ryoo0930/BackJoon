//1260
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DFS(int** graph, bool* visited, int vertex, int key);
void BFS(int** graph, bool* visited, int vertex, int key);

int main(void) {
	int vertex = 0, edge = 0, key = 0;
	scanf("%d %d %d", &vertex, &edge, &key);

	int** graph = (int**)calloc(vertex + 1, sizeof(int*)); //그래프 인접 행렬.
	for (int i = 0; i < vertex + 1; i++) {
		graph[i] = (int*)calloc(vertex + 1, sizeof(int));
	}
	bool* visited = (bool*)calloc(vertex + 1, sizeof(bool)); //그래프 방문 여부.


	for (int i = 0; i < edge; i++) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(graph, visited, vertex, key);
	printf("\n");
	for (int i = 1; i <= vertex; i++) { visited[i] = 0; } // 방문 초기화
	BFS(graph, visited, vertex, key);




	for (int i = 0; i < vertex + 1; i++) {
		free(graph[i]);
	}
	free(graph);
	return 0;
}

void DFS(int** graph, bool* visited, int vertex, int key) {
	visited[key] = 1;
	printf("%d ", key);

	for (int i = 1; i < vertex + 1; i++) {
		if (graph[key][i] == 1 && visited[i] == 0) {
			DFS(graph, visited, vertex, i);
		}
	}
}

void BFS(int** graph, bool* visited, int vertex, int key) {
	int* queue = (int*)calloc(vertex + 1, sizeof(int)); //BFS를 위한 큐
	int front = 0, rear = 0;

	queue[rear++] = key;
	visited[key] = true;

	while (front < rear) {
		int node = queue[front++];
		printf("%d ", node);

		for (int i = 1; i < vertex + 1; i++) {
			if (graph[node][i] == 1 && !visited[i]) {
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}

	free(queue);
}