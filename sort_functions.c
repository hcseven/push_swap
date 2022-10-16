/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:06:36 by hseven            #+#    #+#             */
/*   Updated: 2022/10/11 20:24:20 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_a(t_data *data, int a)
{
	int	b;
	int	c;

	b = find_which_index(data, data->b_arr[a]);
	c = data->i_arr[b];
	if (b == data->len_i - 1)
		return ;
	else if (b < data->len_i / 2)
	{
		while (data->i_arr[data->len_i - 1] != c)
			r_rotate_a(data);
	}
	else if ((b >= data->len_i / 2))
	{
		while (data->i_arr[data->len_i - 1] != c)
			rotate_a(data);
	}
	return ;
}

void	sort_for_b(t_data *data, int a)
{
	if (data->len_b - 1 == a)
		return ;
	else if (a < data->len_b / 2)
	{
		a = data->b_arr[a];
		while (data->b_arr[data->len_b - 1] != a)
			r_rotate_b(data);
	}
	else if (a >= data->len_b / 2)
	{
		a = data->b_arr[a];
		while (data->len_b > 1 && data->b_arr[data->len_b - 1] != a)
			rotate_b(data);
	}
	return ;
}
