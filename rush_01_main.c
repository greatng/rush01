/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:51:56 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/22 15:46:23 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_printboard(int board[4][4]);

void	ft_printerror()
{
	write(1, "Error\n", 6);
	exit (0);
}

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

int	main(int argc, char **argv)
{
	int	*clue;
	int	i;
	int	j;

	i = 0;
	j = 0;
	clue = (int *)malloc(16 * sizeof(int));
	while (argv[argc - 1][i] != '\0')
	{
		if (argv[argc - 1][i] >= '1' && argv[argc - 1][i] <= '4' && i % 2 == 0)
			clue[j++] = argv[argc - 1][i] - 48;
		else if (argv[argc - 1][i] != ' ')
		{
			ft_printerror();
		}
		i++;
	}
	if (j != 16)
	{
		ft_printerror();
	}
	ft_clue(clue, 0, 4);
}
//ft_wallchecker
//ft_fillvoid

void	ft_printboard(int board[4][4])
{
	int		i;
	char	temp;

	i = 0;
	while (i < 16)
	{
		temp = board[i / 4][i % 4] + 48;
		write(1, &temp, 1);
		if (i % 4 == 3)
		{
			write(1, "\n", 1);
		}
		else
			write(1, " ", 1);
		i++;
	}
}
