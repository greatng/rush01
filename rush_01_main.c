/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:51:56 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/22 15:10:22 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_printboard(int *board);

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
		if (argv[argc - 1][i] >= '1' && argv[argc - 1][i] <= '4')
		{
			clue[j++] = argv[argc - 1][i] - 48;
			//printf("%d\n", clue[j - 1]);
		}
		else if (argv[argc - 1][i] != ' ')
			printf("Error 1\n");
		i++;
	}
	if (j != 16)
		printf("Error 2\n");
	ft_printboard(clue);
}
//ft_iscluevalid
//ft_fillvoid
//ft_printboard
//still missing some condition check like 11 12 21 22 the program won't error even it should do.

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
