#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int health;
	int attack;
}player;

int main() {
	player playerA, playerB;
	scanf("%d %d", &playerA.attack, &playerA.health);
	scanf("%d %d", &playerB.attack, &playerB.health);

	while (1) {
		playerA.health -= playerB.attack;
		playerB.health -= playerA.attack;
		if (playerA.health <= 0 || playerB.health <= 0) break;
	}

	if (playerA.health > 0) printf("PLAYER A");
	else if (playerB.health > 0) printf("PLAYER B");
	else printf("DRAW");

	return 0;
}
