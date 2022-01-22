#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"
//printer only as they named
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

void	ft_printerror()
{
	write(1, "Error\n", 6);
	exit (0);
}