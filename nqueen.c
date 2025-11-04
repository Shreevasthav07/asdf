#include <stdio.h>
#define N 4  // You can change this to any N (e.g., 8 for 8-queens)

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if a queen can be placed on board[row][col]
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1; // Safe position
}

int solveNQUtil(int board[N][N], int row) {
    if (row == N) {
        printSolution(board);
        return 1;
    }

    int res = 0; // To check if at least one solution exists
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;           // Place queen
            res = solveNQUtil(board, row + 1) || res;  // Recurse
            board[row][col] = 0;           // Backtrack
        }
    }
    return res;
}

void solveNQ() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == 0)
        printf("No solution exists\n");
}

int main() {
    solveNQ();
    return 0;
}
