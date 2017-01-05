#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_check_mult(int c, int q, int b)
{
	if (c == q * b)
		return (1);
	return (0);
}

int		ft_check_div(int c, int q, int b)
{
	if (c == b / q)
		return (1);
	return (0);
}
/*
int		ft_is_geom_mult(int b, int c, int i, char *str)
{
	if ((a != 0) && (c >= b) && (b >= a))
	{
		q = b / a;
		while (b <= c && ft_check_mult(c, q, b))
		{
			b = c;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			if (str[i] == ' ')
				c = atoi(str + i + 1);
			if (str[i] == '\0')
			{
				printf("%d", c * q);
				return ;
			}
			i++;
		}
	}

}*/
int	ft_parse_input(char *str)
{
	int cmp;
	int i;

	cmp = 1;
	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (str[i] == ' ' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		else if (str[i] == ' ' && !(str[i] >= '0' && str[i] <= '9'))
			cmp++;
		i++;
	}
	if (cmp < 2)
		return (0);
	return (1);
}

void	ft_next(char *str)
{
	int a;
	int b;
	int c;
	int	i;
	int q;
	
	if (!ft_parse_input(str))
	{
		printf("Error\n");
		return ;
	}

	printf("cest passe\n");
	i = 0;
	a = atoi(str);
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	b = atoi(str + i + 1);
	i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	c = atoi(str + i + 1);
	i++;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	if ((a != 0) && (c >= b) && (b >= a))
	{
		q = b / a;
		while (b <= c && ft_check_mult(c, q, b))
		{
			b = c;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			if (str[i] == ' ')
				c = atoi(str + i + 1);
			if (str[i] == '\0')
			{
				printf("%d", c * q);
				return ;
			}
			i++;
		}
	}
	if ((b != 0) && (c <= b) && (b <= a))
	{
		q = a / b;
		while (c <= b && ft_check_div(c, q, b))
		{
			b = c;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			if (str[i] == ' ')
				c = atoi(str + i + 1);
			if (str[i] == '\0')
			{
				printf("%d", c / q);
				return ;
			}
			i++;
		}
	}
	printf("Error\n");
}

int		main(int ac, char**av)
{
	if (ac == 2)
		ft_next(av[1]);
	return(0);
}
