/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calculate_step.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:21:36 by hseven            #+#    #+#             */
/*   Updated: 2022/10/12 12:59:13 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_step(t_data *data)
{
	int	step_a;
	int	step_b;
	int	top_step;
	int	best_index;
	int	b_index;

	step_a = 0;
	step_b = 0;
	b_index = 0;
	top_step = step_a + step_b;
	best_index = 0;
	while (data->len_b > b_index)
	{
		step_a = calculate_step_for_a(data, data->b_arr[b_index]);
		step_b = calculate_step_for_b(data, b_index);
		if (top_step > step_a + step_b || top_step == 0)
		{
			top_step = step_a + step_b;
			best_index = b_index;
		}
		b_index++;
	}
	return (best_index);
}

int	calculate_step_for_a(t_data *data, int num)
{
	int	index_a;

	index_a = find_which_index(data, num);
	if (index_a == data->len_i - 1)
		return (0);
	else if (index_a == data->len_i - 2)
		return (1);
	else if (index_a >= data->len_i / 2)
		return ((data->len_i - index_a) - 1);
	else if (index_a < data->len_i / 2)
		return (index_a + 1);
	return (-1000);
}

int	calculate_step_for_b(t_data *data, int index)
{
	if (index == data->len_b - 1)
		return (1);
	else if (index == data->len_b - 2)
		return (2);
	else if (index >= data->len_b / 2)
		return (data->len_b - index);
	else if (index < data->len_b / 2)
		return (index + 2);
	return (-1000);
}
