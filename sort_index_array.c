/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:47:27 by hseven            #+#    #+#             */
/*   Updated: 2022/10/15 22:18:39 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	get_index(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = data->len_a;
	while (data->len_a > i)
	{
		data->i_arr[i] = find_index(data->a_arr, size, data->a_arr[i]);
		i++;
	}
	data->len_i = i;
	return ;
}

int	find_index(int *a_arr, int len, int min)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (len > a)
	{
		if (a_arr[a] < min)
			b++;
		a++;
	}
	return (b);
}
