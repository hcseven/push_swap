/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_array_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:03:41 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:03:42 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	def_td_array_toint(t_data *data, char **str)
{
	int	a;

	a = 0;
	while (str[a] != (void *) '\0')
	{
		if (count_plus_minus(str[a]) > 1)
			return (2);
		if (ft_atoi(str[a]) > 2147483647 || ft_atoi(str[a]) < -2147483648)
			return (2);
		data->a_arr[data->len_i - 1] = ft_atoi(str[a]);
		data->len_a--;
		a++;
	}
	return (0);
}

int	get_array(t_data *data, char **av, int ac)
{
	int		a;
	char	**str;

	a = 1;
	data->len_a = data->size;
	while (ac > a)
	{
		if (count_space(av[a]) != 0)
		{
			str = ft_split(av[a], 32);
			if (def_td_array_toint(data, str) == 2)
				return (0);
		}
		else
		{
			if (count_plus_minus(av[a]) > 1 || (ft_atoi(av[a]) > 2147483647
					|| ft_atoi(av[a]) < -2147483648))
				return (0);
			data->a_arr[data->len_a - 1] = ft_atoi(av[a]);
			data->len_a--;
		}
		a++;
	}
	data->len_a = data->size;
	return (1);
}
