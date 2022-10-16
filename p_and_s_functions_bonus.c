/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_and_s_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:28:57 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:09:35 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_push_a(t_data	*data)
{
	if (data->len_b == 0)
		return ;
	data->a_arr[data->len_a] = data->b_arr[data->len_b - 1];
	data->len_a++;
	data->len_b--;
	data->step_count++;
}

void	b_push_b(t_data	*data)
{
	data->b_arr[data->len_b] = data->a_arr[data->len_a - 1];
	data->len_a--;
	data->len_b++;
	data->step_count++;
}

void	b_swap_a(t_data *data)
{
	int	a;

	a = data->a_arr[data->len_a - 1];
	data->a_arr[data->len_a - 1] = data->a_arr[data->len_a - 2];
	data->a_arr[data->len_a - 2] = a;
	data->step_count++;
}

void	b_swap_b(t_data *data)
{
	int	a;

	a = data->b_arr[data->len_b - 1];
	data->b_arr[data->len_b - 1] = data->b_arr[data->len_b - 2];
	data->b_arr[data->len_b - 2] = a;
	data->step_count++;
}

void	b_swap_ab(t_data *data)
{
	b_swap_a(data);
	data->step_count--;
	b_swap_b(data);
}
