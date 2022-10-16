/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:16:07 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 00:19:46 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_to_b(t_data *data)
{
	int	a;

	a = data->len_i - 1;
	while (data->len_i > 2)
	{
		if (data->i_arr[a] < average_array(data))
		{	
			push_b(data);
			a--;
		}
		else
			rotate_a(data);
	}
}

int	find_which_index(t_data *data, int num)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (data->len_i > a)
	{
		if (data->i_arr[a] > num)
			b = a;
		a++;
	}
	a = 0;
	while (data->len_i > a)
	{
		if (data->i_arr[a] > num)
		{
			if (data->i_arr[b] > data->i_arr[a])
				b = a;
		}	
		a++;
	}
	return (b);
}

void	last_look(t_data *data)
{
	int	b;

	b = find_max(data);
	if (b == 0)
		return ;
	else if (b <= data->len_i / 2)
	{
		while (b > 0)
		{
			r_rotate_a(data);
			b--;
		}
	}
	else if (data->len_i / 2 < b)
	{
		while (b < data->len_i)
		{
			rotate_a(data);
			b++;
		}
	}
	return ;
}

void	sort_alg(t_data *data)
{
	int	a;
	int	b;

	if (data->len_i <= 5)
	{
		sort_small_var(data);
		free_data(data, 15);
	}
	sort_push_to_b(data);
	a = data->len_b;
	while (a > 0)
	{
		b = count_step(data);
		sort_for_a(data, b);
		sort_for_b(data, b);
		push_a(data);
		a--;
	}
	last_look(data);
}
