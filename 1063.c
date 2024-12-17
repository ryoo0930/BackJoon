#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} piece;

void checkRange(piece* p);

int main(void) {
    piece king, stone;
    char king_char_x, stone_char_x;
    int times;

    // 입력 받기
    scanf("%c%d %c%d %d", &king_char_x, &king.y, &stone_char_x, &stone.y, &times);
    getchar();
    king.x = king_char_x - 'A'; king.y -= 1;
    stone.x = stone_char_x - 'A'; stone.y -= 1;

    for (int t = 0; t < times; t++) {
        char move[3];
        scanf("%s", move);

        int dx = 0, dy = 0;
        if (strcmp(move, "R") == 0) { dx = 1; }
        else if (strcmp(move, "L") == 0) { dx = -1; }
        else if (strcmp(move, "B") == 0) { dy = -1; }
        else if (strcmp(move, "T") == 0) { dy = 1; }
        else if (strcmp(move, "RT") == 0) { dx = 1; dy = 1; }
        else if (strcmp(move, "LT") == 0) { dx = -1; dy = 1; }
        else if (strcmp(move, "RB") == 0) { dx = 1; dy = -1; }
        else if (strcmp(move, "LB") == 0) { dx = -1; dy = -1; }

        int nextKingX = king.x + dx;
        int nextKingY = king.y + dy;

        if (nextKingX >= 0 && nextKingX < 8 && nextKingY >= 0 && nextKingY < 8) {
            
            if (nextKingX == stone.x && nextKingY == stone.y) {
                int nextStoneX = stone.x + dx;
                int nextStoneY = stone.y + dy;

                if (nextStoneX >= 0 && nextStoneX < 8 && nextStoneY >= 0 && nextStoneY < 8) {
                    king.x = nextKingX;
                    king.y = nextKingY;
                    stone.x = nextStoneX;
                    stone.y = nextStoneY;
                }
            }
            else {
                king.x = nextKingX;
                king.y = nextKingY;
            }
        }
    }

    printf("%c%d\n", king.x + 'A', king.y + 1);
    printf("%c%d\n", stone.x + 'A', stone.y + 1);

    return 0;
}

void checkRange(piece* p) {
    if (p->x < 0) p->x = 0;
    if (p->x > 7) p->x = 7;
    if (p->y < 0) p->y = 0;
    if (p->y > 7) p->y = 7;
}
