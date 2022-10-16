/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_and_s_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:28:57 by hseven            #+#    #+#             */
/*   Updated: 2022/10/11 20:27:24 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data	*data)
{
	data->i_arr[data->len_i] = data->b_arr[data->len_b - 1];
	data->len_i++;
	data->len_b--;
	data->step_count++;
	write(1, "pa\n", 3);
}

void	push_b(t_data	*data)
{
	data->b_arr[data->len_b] = data->i_arr[data->len_i - 1];
	data->len_i--;
	data->len_b++;
	data->step_count++;
	write(1, "pb\n", 3);
}

void	swap_a(t_data *data, int b)
{
	int	a;

	a = data->i_arr[data->len_i - 1];
	data->i_arr[data->len_i - 1] = data->i_arr[data->len_i - 2];
	data->i_arr[data->len_i - 2] = a;
	data->step_count++;
	if (b == 1)
		write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_data *data, int b)
{
	int	a;

	if (data->len_b > 2)
	{
		a = data->b_arr[data->len_b - 1];
		data->b_arr[data->len_b - 1] = data->b_arr[data->len_b - 2];
		data->b_arr[data->len_b - 2] = a;
		data->step_count++;
		if (b == 1)
			write(1, "sb\n", 3);
	}
}

void	swap_ab(t_data *data)
{
	swap_a(data, 0);
	data->step_count--;
	swap_b(data, 0);
	write(1, "ss\n", 3);
}
