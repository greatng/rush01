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

void	ft_printboard(int *board);

void	ft_printerror()
{
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_clue(int *clue, int i, int j)
{
	while (clue[i] && i < 16)
	{
		if (i == 4)
		j = 15;
		if (i == 8)
		j = 3;
		if (i == 12)
		j = 7;
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
		j--;
	}
	printf("The clues are valid\n");
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
	ft_clue(clue, 0, 11);
}
//ft_iscluevalid
//ft_fillvoid

void	ft_printboard(int *board)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 16)
	{
		temp = board[i] + 48;
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
