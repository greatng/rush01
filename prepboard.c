#include "rush01.h"

void	ft_fillboard(int board[4][4], int i)
{
	int	n;
	
	n=0;
	while (n++ < 4)
	{
		if ( i >= 0 && i <= 3)
		board[0][i + n - 1] = n;
		if ( i >= 4 && i <= 7)
		board[3][(i % 4) + n - 1] = n;
		if ( i >= 8 && i <= 11)
		board[i - 9 + n][0] = n;
		if ( i >= 12 && i <= 15)
		board[(i % 4) + n - 1][3] = n;
	}
}

//this function here will check if clue 1 is available it will fill the rest
void	ft_check1(int *clue, int board[4][4], int i)
{
	while (i < 16)
	{
		if (clue[i] == 4 )
		{
			ft_fillboard(board, i);
		}
		i++;
	}
}

//we will check if there is 1 in clues then fill 4
void	ft_start(int *clue)
{
	int	board[4][4];
	int	i;

	i = 0;
	while (i < 16)
	{
		board[i / 4][i % 4] = 0;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (clue[i] == 1 )
		{
			if ( i >= 0 && i <= 3)
			board[0][i] = 4;
			if ( i >= 4 && i <= 7)
			board[3][i % 4] = 4;
			if ( i >= 8 && i <= 11)
			board[i - 8][0] = 4;
			if ( i >= 12 && i <= 15)
			board[i % 4][3] = 4;
		}
		i++;
	}
	ft_check1(clue, board, 0);
	ft_printboard(board); //now we have partial filled board
}

void	ft_clue(int *clue, int i, int j)
{
	while (clue[i] && i < 16)
	{
		if (i == 4)
		j = 0;
		if (i == 8)
		j = 12;
		if (i == 12)
		j = 8;
		if (clue[i] == 1 && clue[j] == 1)
			ft_printerror();
		if (clue[i] == 2 && clue[j] == 4)
			ft_printerror();
		if (clue[i] == 3 && clue[j] == 3)
			ft_printerror();
		if (clue[i] == 3 && clue[j] == 3)
			ft_printerror();
		if (clue[i] == 4 && clue[j] == 4)
			ft_printerror();
		i++;
		j++;
	}
	ft_start(clue);
}