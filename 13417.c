#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1001

typedef struct {
	char table[MAXSIZE];
	int front;
	int rear;
}Deque;

void init_deque(Deque* deque);
void push_front(Deque* deque, char data);
void push_back(Deque* deque, char data);
char print_front(Deque* deque);
char print_back(Deque* deque);
void print_deque(Deque* deque);

int main()
{	
	int testCase = 0;
	scanf("%d", &testCase);
	
	while (testCase--) {
		Deque deque;
		init_deque(&deque);

		int size = 0;
		scanf("%d", &size);
		getchar();

		for (int i = 0; i < size; i++) {
			char card;
			scanf("%c", &card);
			getchar();

			if (print_front(&deque) >= card) push_front(&deque, card);
			else push_back(&deque, card);
		}
		print_deque(&deque);
	}

	return 0;
}

void init_deque(Deque* deque) {
	deque->front = 0;
	deque->rear = 0;
}
void push_front(Deque* deque, char data) {
	deque->front = (deque->front - 1 + MAXSIZE) % MAXSIZE;
	deque->table[deque->front] = data;
}
void push_back(Deque* deque, char data) {
	deque->table[deque->rear] = data;
	deque->rear = (deque->rear + 1) % MAXSIZE;
}
char print_front(Deque* deque) {
	int index = deque->front;
	return deque->table[index];
}
char print_back(Deque* deque) {
	int index = (deque->rear - 1 + MAXSIZE) % MAXSIZE;
	return deque->table[index];
}
void print_deque(Deque* deque) {
	int index = deque->front;
	while (index != deque->rear) {
		printf("%c", deque->table[index]);
		index = (index + 1) % MAXSIZE;
	}
	printf("\n");
}
