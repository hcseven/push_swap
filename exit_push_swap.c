/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:59:34 by hseven            #+#    #+#             */
/*   Updated: 2022/10/15 10:26:33 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *data, int a)
{
	if (a == 0)
		write(1, "Your array has same integer variables.\n", 40);
	if (a == 1)
		write(1, "your array is in order\n", 23);
	if (a == 2)
		write(1, "Your input has forbidden character\n", 36);
	if (a == 3)
		write(1, "Error\n", 6);
	free (data->a_arr);
	free (data->i_arr);
	free (data->b_arr);
	free (data);
	exit(0);
}
