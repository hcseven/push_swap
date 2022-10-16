/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:53:42 by hseven            #+#    #+#             */
/*   Updated: 2022/10/15 22:17:56 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	average_array(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < data->len_i)
	{	
		b += data->i_arr[a];
		a++;
	}
	return (b / a);
}

int	find_max(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (data->len_i > a)
	{
		if (b == 0 && a == 0)
			b = a;
		else if (data->i_arr[a] > data->i_arr[b])
			b = a;
		a++;
	}
	return (b);
}

int	count_space(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a] != '\0')
	{
		if (str[a] == 32 && str[a + 1] != 32)
			b++;
		a++;
	}
	return (b);
}

int	arg_counter(char **av, int ac)
{
	int	a;
	int	b;

	a = 1;
	b = 0;
	while (ac > a)
	{
		if (count_space(av[a]) != 0)
			b += count_space(av[a]);
		a++;
		b++;
	}
	return (b);
}
