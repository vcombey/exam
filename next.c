/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:34:48 by vcombey           #+#    #+#             */
/*   Updated: 2017/01/05 19:34:50 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if ((str[i] != ' ') && (str[i] != '-') && !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if ((str[i] == ' ') && (str[i] != '-') && !((str[i + 1] >= '0') && (str[i + 1] <= '9')))
			return (0);
		else if (str[i] == ' ')
			cmp++;
		else if (str[i] == '-' && (!((str[i + 1] >= '0') && (str[i + 1] <= '9'))))
			return (0);
		i++;
	}
	if (cmp < 2)
		return (0);
	return (1);
}

int		check_zeros(char *str, int i)
{
	while (str[i])
	{
		while ((str[i] >= '0') && (str[i] <= '9'))
			i++;
		if (str[i] == ' ')
		{
			if (atoi(str + i + 1) != 0)
			return (0);
		}
		i++;
	}
	printf("0\n");
	return (1);
}

void	ft_next(char *str)
{
	int a;
	int b;
	int	i;
	int q;
	
	if (!(ft_parse_input(str)))
	{
		printf("Error\n");
		return ;
	}
	i = 0;
	a = atoi(str);
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	b = atoi(str + i + 1);
	i++;
	if (b == 0 && check_zeros(str, i))
		return ;
	if ((a != 0) && (b >= a))
	{
		q = b / a;
		while (a <= b && ft_check_mult(b, q, a))
		{
			a = b;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			if (str[i] == ' ')
				b = atoi(str + i + 1);
			if (str[i] == '\0')
			{
				printf("%d\n", b * q);
				return ;
			}
			i++;
		}
		printf("Error\n");
	}
	if ((b != 0) && (b <= a))
	{
		q = a / b;
		while (b <= a && ft_check_div(b, q, a))
		{
			a = b;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			if (str[i] == ' ')
				b = atoi(str + i + 1);
			if (str[i] == '\0')
			{
				printf("%d\n", b / q);
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
	else
		printf("Error\n");
	return(0);
}
