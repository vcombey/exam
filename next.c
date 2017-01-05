#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_display(int *tab, int nb)
{
	int cmp;
	
	cmp = 0;
	while (cmp < nb)
	{
		printf("%d", tab[cmp]);
		cmp++;
	}
}
int		ft_nb_int(char *str)
{
	int i;
	int cmp;

	cmp = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			cmp++;
		i++;
	}
	return (cmp);
}

void	ft_next(char *str)
{
	int nb;
	int *tab;
	int i;
	int cmp;

	cmp = 0;
	i = 0;
	nb = ft_nb_int(str);
	tab = malloc(sizeof(int) * nb);
	tab[cmp] = atoi(str);
	while (i < nb)
	{
		if (str[i] == ' ')
		{
			tab[cmp] = atoi(str + i +1);
			cmp++;
		}
		i++;
	}
	ft_display(tab, nb);
}

int		main(int ac, char**av)
{
	if (ac == 2)
		ft_next(av[1]);
	write(1, "\n", 1);
	return(0);
}

