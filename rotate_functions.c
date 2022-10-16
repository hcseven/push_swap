/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:45:27 by hseven            #+#    #+#             */
/*   Updated: 2022/10/11 20:28:09 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	int	a;
	int	b;

	b = data->i_arr[0];
	a = 0;
	while (data->len_i - 1 > a)
	{
		data->i_arr[a] = data->i_arr[a + 1];
		a++;
	}
	data->i_arr[data->len_i - 1] = b;
	data->step_count++;
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_data *data)
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
	write(1, "rrb\n", 4);
}

void	rotate_a(t_data *data)
{
	int	a;
	int	b;

	b = data->i_arr[data->len_i - 1];
	a = data->len_i - 2;
	while (a >= 0)
	{	
		data->i_arr[a + 1] = data->i_arr[a];
		a--;
	}
	data->i_arr[0] = b;
	data->step_count++;
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
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
	write(1, "rb\n", 3);
}
