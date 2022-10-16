/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_small_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:13:11 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 00:20:39 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rev_order(t_data *data)
{
	if (data->len_i == 3 && data->i_arr[0] < data->i_arr[1]
		&& data->i_arr[1] < data->i_arr[2])
		return (0);
	else if (data->len_i == 4 && data->i_arr[0] > data->i_arr[1]
		&& data->i_arr[1] > data->i_arr[2] && data->i_arr[2] > data->i_arr[3])
		return (0);
	else if (data->len_i == 5 && data->i_arr[0] > data->i_arr[1]
		&& data->i_arr[1] > data->i_arr[2] && data->i_arr[2] > data->i_arr[3]
		&& data->i_arr[3] > data->i_arr[4])
		return (0);
	return (1);
}

int	max(int *arr, int len, int mm)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (mm == 1)
	{
		while (len > a)
		{
			if (arr[a] > arr[b])
				b = a;
			a++;
		}
	}
	else if (mm == 0)
	{
		while (len > a)
		{
			if (arr[a] < arr[b])
				b = a;
			a++;
		}
	}
	return (b);
}

void	sort_for_three(t_data *data)
{
	int	b;

	b = data->len_i;
	if (check_rev_order(data) == 0)
	{
		rotate_a(data);
		swap_a(data, 1);
	}
	else if (check_rev_order(data) == 1)
	{
		if (data->i_arr[0] > data->i_arr[1] && max(data->i_arr, b, 1) == 2)
			rotate_a(data);
		else if (data->i_arr[2] > data->i_arr[1] && max(data->i_arr, b, 1) == 0)
			swap_a(data, 1);
		else if (data->i_arr[2] > data->i_arr[0] && max(data->i_arr, b, 1) == 1)
			r_rotate_a(data);
		else if (data->i_arr[0] > data->i_arr[2] && max(data->i_arr, b, 1) == 1)
		{
			swap_a(data, 1);
			rotate_a(data);
		}
	}
}

void	sort_for_five(t_data *data)
{
	int	b;

	b = max(data->i_arr, data->len_i, 0);
	if (b == 0 || b == 1 || b == 2)
	{
		while (b-- > -1)
			r_rotate_a(data);
	}
	else if (b == 3)
		rotate_a(data);
	push_b(data);
	sort_small_var(data);
	push_a(data);
}

void	sort_small_var(t_data *data)
{
	int	b;

	b = data->len_i;
	if (b == 2)
		swap_a(data, 1);
	else if (b == 3)
		sort_for_three(data);
	else if (b == 4)
	{
		b = max(data->i_arr, data->len_i, 0);
		if (b == 0 || b == 1)
		{
			while (b-- > -1)
				r_rotate_a(data);
		}	
		else if (b == 2)
			rotate_a(data);
		push_b(data);
		sort_for_three(data);
		push_a(data);
	}
	else if (b == 5)
		sort_for_five(data);
}
