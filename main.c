#include <stdlib.h>
#include "rush01.h"
//this main only check if argument is correct
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