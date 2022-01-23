#include <stdbool.h>
#include "rush01.h"
#include <stdio.h>
#define N 4
#define UNASSIGNED 0

// Checks whether it will be legal
// to assign num to the given row, col
bool clueCheck(int board[N][N], int clue);

bool isSafe(int board[N][N], int *clue, int i, int j, int n);
 
/* Takes a partially filled-in grid
   and attempts to assign values to
   all unassigned locations in such
   a way to meet the requirements
  for Sudoku solution (non-duplication
  across rows, columns, and boxes) */
int ft_solve(int board[N][N], int *clue, int i, int j)
{
    int n;
    int ans;
    //int copy[N][N];
    if (i == N - 1 && j== N)
    {
        ft_printboard(board);
        if (ft_checker(board, clue) == 0)
            return 0;
        return 1;
    }
 
    //  Check if column value  becomes 4 ,
    //  we move to next row and
    //  column start from 0
    if (j == N)
    {
        /*
        printf("We need to check row here %d\n", j);
        ft_clueCheck
        */
        i++;
        j = 0;
    }
   
    // Check if the current position
    // of the grid already contains
    // value >0, we iterate for next column
    if (board[i][j] > 0)
        return ft_solve(board, clue, i, j + 1);

    n = 1;  //Consider digits 1 to 4
    while (n < 5)
    {
        // Check if looks promising
        if (isSafe(board, clue, i, j, n))
        {
            // Make tentative assignment
            board[i][j] = n;
            //printf("i = %d, j = %d, n = %d\n", i, j, n);
            // Return, if success, yay!
            if (ft_solve(board, clue, i, j))
            {
                //printf("Recurred\n");
                return (1);
            }
            // Failure, unmake & try again
            board[i][j] = UNASSIGNED;
        }
        //printf("WHile loop\n");
        n++;
    }
    //printf("Out of loop\n");
    // This triggers backtracking
    return (0);
}
/* Returns a boolean which indicates
   whether an assigned entry
   in the specified row matches the
   given number. */
bool rowCheck(int board[N][N], int i, int n)
{
    int j;

    j = 0;
    while (j < N)
    {
        if (board[i][j] == n)
            return true;
        j++;
    }
    return false;
}
 
/* Returns a boolean which indicates
   whether an assigned entry
   in the specified column matches
   the given number. */
bool colCheck(int board[N][N], int j, int n)
{
    int i;

    i = 0;
    while (i < N)
    {
        if (board[i][j] == n)
            return true;
        i++;     
    }
    return false;
}
 
/* Returns a boolean which indicates
whether it will be legal to assign
   num to the given row, col location. */
bool isSafe(int board[N][N], int *clue, int i, int j, int n)
{
     
    /* Check if 'num' is not already placed
       in current row, current column and
       current 3x3 box */
    return !rowCheck(board, i, n) && !colCheck(board, j, n) && board[i][j] == UNASSIGNED;
}
 