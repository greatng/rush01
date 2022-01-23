#ifndef RUSH01
#define RUSH01
#define N 4
#include <stdbool.h>
void	ft_printboard(int board[4][4]);

void	ft_printerror();

void	ft_fillboard(int board[4][4], int i);

void	ft_check1(int *clue, int board[4][4], int i);

void	ft_start(int *clue);

void	ft_clue(int *clue, int i, int j);

int    ft_solve(int board[N][N], int *clue, int i, int j);
#endif