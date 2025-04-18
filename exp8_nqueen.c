#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int board[MAX][MAX];
void printSolution(int n)
{
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
// Check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, int n)
{
    int i, j;
    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;
    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;
    return true;
}
// Solve the problem using backtracking
bool solveNQueens(int row, int n)
{
    if (row >= n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 1;
            if (solveNQueens(row + 1, n))
                return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}
int main()
{
    int n;
    printf("Enter the value of N (size of board): ");
    scanf("%d", &n);
    // Initialize the board with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    if (solveNQueens(0, n))
        printSolution(n);
    else
        printf("No solution exists for %d-Queens.\n", n);
    return 0;
}