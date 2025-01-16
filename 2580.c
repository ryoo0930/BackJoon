#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[9][9];
bool check(int row, int col, int num);
bool sudoku();

int main() {
	for (int i = 0; i < 9; i++) { for (int j = 0; j < 9; j++) { scanf("%d", &board[i][j]); } }

	sudoku();
	for (int i = 0; i < 9; i++) { for (int j = 0; j < 9; j++) { printf("%d ", board[i][j]); } printf("\n"); }

	return 0;
}

bool check(int row, int col, int num) {
	for (int i = 0; i < 9; i++) { if (board[row][i] == num) return false; } // 가로
	for (int i = 0; i < 9; i++) { if (board[i][col] == num) return false; } // 세로

	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) { if (board[startRow + i][startCol + j] == num) return false; } } // 3 x 3
	return true;
}

bool sudoku() {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {

			if (board[row][col] == 0) {
				for (int num = 1; num <= 9; num++) {
					if (check(row, col, num)) {
						board[row][col] = num;

						if (sudoku() == true) return true;
						board[row][col] = 0; // rollback
					}
				}
				return false;
			}

		}
	}
	return true;
}
