/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:17:54 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/23 20:18:10 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "rush01.h"
#define UNASSIGNED 0
#define N 4

void	ft_fillboard(int board[N][N], int i)
{
	int	n;
	
	n = 0;
	while (n++ < 4)
	{
		if ( i >= 0 && i <= 3)
		board[0][i + n - 1] = n;
		if ( i >= 4 && i <= 7)
		board[4 - n][i - 4] = n;
		if ( i >= 8 && i <= 11)
		board[i - 9 + n][0] = n;
		if ( i >= 12 && i <= 15)
		board[i % 4][4 - n] = n; 
	}
}

void	ft_check1(int *clue, int board[N][N], int i)
{
    while (i < 16)
	{
		board[i / 4][i % 4] = UNASSIGNED;
		i++;
	}
    i = 0;
	while (i < 16)
	{
		if (clue[i] == 4 )
		{
			ft_fillboard(board, i);
		}
		i++;
	}
}

void	ft_start(int *clue)
{
	int	board[N][N];
	int	i;

	ft_check1(clue, board, 0);
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
	if (ft_solve(board, clue, 0, 0))
		ft_printboard(board);
	else
		ft_printerror();
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
