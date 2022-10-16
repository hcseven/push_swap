/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:22:20 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:10:45 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_sort(t_data *data)
{
	int	a;

	a = 0;
	if (data->len_b != 0)
	{
		write(1, "KO\n", 3);
		free_data(data, 15);
	}
	while (data->len_a - 1 > a)
	{
		if (data->a_arr[a] < data->a_arr[a + 1])
		{
			write (1, "KO\n", 3);
			free_data(data, 15);
		}
		a++;
	}
	write(1, "OK\n", 3);
	return ;
}

void	input_use(t_data *data, char *s)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		b_push_a(data);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		b_push_b(data);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		b_rotate_a(data);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		b_rotate_b(data);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		b_rotate_r(data, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		b_r_rotate_a(data);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		b_r_rotate_b(data);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		b_rotate_r(data, 1);
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		b_swap_a(data);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		b_swap_b(data);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		b_swap_ab(data);
}

int	input_check(t_data *data, char *s)
{
	int	a;

	a = 0;
	if (s[0] == 'p' && (s[1] == 'a' || s[1] == 'b') && s[2] == '\n')
		a = 1;
	else if (s[0] == 'r' && (s[1] == 'a' || s[1] == 'b' || s[1] == 'r')
		&& s[2] == '\n')
		a = 1;
	else if (s[0] == 'r' && s[1] == 'r' && s[3] == '\n'
		&& (s[2] == 'a' || s[2] == 'b' || s[2] == 'r'))
		a = 1;
	else if (s[0] == 's' && s[2] == '\n'
		&& (s[1] == 'a' || s[1] == 'b' || s[1] == 's'))
		a = 1;
	if (a == 1)
		input_use(data, s);
	return (a);
}

int	read_input(t_data *data)
{
	int		b;
	int		a;
	char	*s;

	s = ft_calloc(4, sizeof(char));
	a = read(0, s, 4);
	b = 5;
	while (a != 0 && b != 0)
	{
		b = input_check(data, s);
		a = read(0, s, 4);
	}
	if (b == 0)
		free_data(data, 2);
	free(s);
	return (0);
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
		if (check_var(av, ac) == 0)
			free_data(data, 2);
		if (get_array(data, av, ac) == 0)
			free_data(data, 3);
		if (check_equals(data) == 0)
			free_data(data, 0);
		if (check_in_order(data) == 0)
			free_data(data, 1);
		read_input(data);
		ft_check_sort(data);
		free_data(data, 15);
	}
	return (0);
}
