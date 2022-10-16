/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:11:13 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:01:34 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	check_var(char **av, int ac)
{
	int	a;
	int	b;

	a = 1;
	while (ac > a)
	{
		b = 0;
		if (av[a][0] == '\0')
			return (0);
		while (av[a][b] != '\0')
		{
			if (ft_isright(av[a][b]) == 0)
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	check_equals(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < data->len_i)
	{
		b = a + 1;
		while (b < data->len_i)
		{
			if (data->a_arr[a] == data->a_arr[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	count_plus_minus(char *av)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (av[a] != '\0')
	{
		if ((av[0] == '-' || av[0] == '+') && (av[1] < '0' || av[1] > '9'))
			return (9);
		if (av[a] == '-' || av[a] == '+')
			b++;
		if (a != 0 && (av[a] == '-' || av[a] == '+'))
			return (10);
		if (b > 1)
			return (b);
		a++;
	}
	return (b);
}

int	check_in_order(t_data *data)
{
	int	a;

	a = 1;
	while (a <= data->size - 1)
	{
		if (data->a_arr[a - 1] > data->a_arr[a])
			a++;
		else
			return (1);
	}
	return (0);
}
