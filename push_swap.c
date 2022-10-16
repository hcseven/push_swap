/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:36:51 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 00:46:08 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	use_functions(t_data *data, char **av, int ac)
{
	if (check_var(av, ac) == 0)
		free_data(data, 2);
	if (get_array(data, av, ac) == 0)
		free_data(data, 3);
	if (check_equals(data) == 0)
		free_data(data, 0);
	if (check_in_order(data) == 0)
		free_data(data, 1);
	get_index(data);
	sort_alg(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac > 2)
	{
		data = malloc(sizeof(t_data) * 1);
		data->size = arg_counter(av, ac);
		data->a_arr = malloc(sizeof(int) * data->size);
		data->b_arr = malloc(sizeof(int) * data->size);
		data->i_arr = malloc(sizeof(int) * data->size);
		data->len_b = 0;
		use_functions(data, av, ac);
		free_data(data, 10);
	}
	return (0);
}
