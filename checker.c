#include "rush01.h"
#include <stdio.h>

int ft_checker(int board[N][N], int *clue)
{
    printf("\nChecker\n");
    if(!(ft_top(board, clue, 0, 0)))
        return (0);
    if(!(ft_btm(board, clue, 3, 0)))
        return (0);
    if(!(ft_left(board, clue, 0, 0)))
        return (0);
    if(!(ft_right(board, clue, 0, 3)))
        return (0);
    ft_printboard(board);
    return (1);
}