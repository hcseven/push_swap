/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:45:27 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:08:53 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_r_rotate_a(t_data *data)
{
	int	a;
	int	b;

	b = data->a_arr[0];
	a = 0;
	while (data->len_a - 1 > a)
	{
		data->a_arr[a] = data->a_arr[a + 1];
		a++;
	}
	data->a_arr[data->len_a - 1] = b;
	data->step_count++;
}

void	b_r_rotate_b(t_data *data)
{
	int	a;
	int	b;

	b = data->b_arr[0];
	a = 0;
	while (data->len_b - 1 > a)
	{
		data->b_arr[a] = data->b_arr[a + 1];
		a++;
	}
	data->b_arr[data->len_b - 1] = b;
	data->step_count++;
}

void	b_rotate_a(t_data *data)
{
	int	a;
	int	b;

	b = data->a_arr[data->len_a - 1];
	a = data->len_a - 2;
	while (a >= 0)
	{	
		data->a_arr[a + 1] = data->a_arr[a];
		a--;
	}
	data->a_arr[0] = b;
	data->step_count++;
}

void	b_rotate_b(t_data *data)
{
	int	a;
	int	b;

	b = data->b_arr[data->len_b - 1];
	a = data->len_b - 1;
	while (a >= 0)
	{
		data->b_arr[a + 1] = data->b_arr[a];
		a--;
	}
	data->b_arr[0] = b;
	data->step_count++;
}

void	b_rotate_r(t_data *data, int a)
{
	if (a == 0)
	{
		b_rotate_a (data);
		b_rotate_b (data);
	}
	else if (a == 1)
	{
		b_r_rotate_a(data);
		b_r_rotate_b(data);
	}
}
