//2606
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enqueue(int* queue, int value);
int dequeue(int* queue);
bool check_empty(int* queue);
int bfs(int** graph, int* queue, bool* visited, int start, int size);
int front = 0, rear = 0; // 큐를 위한 Front, Rear;

int main(void) {
	int computerSize = 0;
	scanf("%d", &computerSize); // 컴퓨터의 개수;

	//인접 행렬 2차월 배열;
	int** graph = (int**)calloc(computerSize + 1, sizeof(int*));
	for (int i = 0; i < computerSize + 1; i++) {
		graph[i] = (int*)calloc(computerSize + 1, sizeof(int));
	}

	//방문 체크 여부 배열;
	bool* visited = (bool*)calloc(computerSize + 1, sizeof(bool));
	//BFS 큐 생성;
	int* queue = (int*)calloc(computerSize + 1, sizeof(int));

	int NetworkSize = 0;
	scanf("%d", &NetworkSize);

	for (int i = 0; i < NetworkSize; i++) {
		int com1 = 0, com2 = 0;
		scanf("%d %d", &com1, &com2);
		graph[com1][com2] = 1;
		graph[com2][com1] = 1;
	}

	int result = bfs(graph, queue, visited, 1, computerSize);
	printf("%d", result);


	//동적 할당 해제;
	free(queue);
	free(visited);
	for (int i = 0; i < computerSize; i++) {
		free(graph[i]);
	}
	free(graph);
	return 0;
}

void enqueue(int* queue, int value) {
	queue[rear++] = value;
}

int dequeue(int* queue) {
	return queue[front++];
}

bool check_empty(int* queue) {
	return front == rear;
}

int bfs(int** graph, int* queue, bool* visited, int start, int size) {
	int infected_count = 0;

	enqueue(queue, start);
	visited[start] = true;

	while (!check_empty(queue)) {
		int current = dequeue(queue);

		for (int i = 1; i <= size; i++) {
			if (graph[current][i] && !visited[i]) {
				enqueue(queue, i);
				visited[i] = true;
				infected_count++;
			}
		}
	}

	return infected_count;
}