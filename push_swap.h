/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:35:18 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 00:17:08 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data{
	int		len_a;
	int		len_b;
	int		len_i;
	int		*a_arr;
	int		*b_arr;
	int		*i_arr;
	int		size;
	int		step_count;
}	t_data;

void	free_data(t_data *data, int a);

char	check_var(char **av, int ac);
int		check_equals(t_data *data);
int		count_plus_minus(char *av);
int		check_in_order(t_data *data);

int		arg_counter(char **av, int ac);
int		count_space(char *str);
int		average_array(t_data *data);
int		find_max(t_data *data);

int		get_array(t_data *data, char **av, int ac);
int		def_td_array_toint(t_data *data, char **str);

long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
int		str_in_array(const char *s, char delimiter);

size_t	ft_strlcpy_ps(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char const *s);
int		ft_isright(int c);

void	push_a(t_data *data);
void	push_b(t_data *data);
void	swap_a(t_data *data, int a);
void	swap_b(t_data *data, int a);
void	swap_ab(t_data *data);

void	use_functions(t_data *data, char **av, int ac);

void	r_rotate_b(t_data *data);
void	r_rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_a(t_data *data);

void	sort_push_to_b(t_data *data);
int		find_which_index(t_data *data, int nm);
void	last_look(t_data *data);
void	sort_alg(t_data *data);

int		count_step(t_data *data);
int		calculate_step_for_a(t_data *data, int a);
int		calculate_step_for_b(t_data *data, int a);

void	sort_small_var(t_data *data);
void	sort_for_five(t_data *data);
void	sort_for_three(t_data *data);
int		max(int *arr, int len, int mm);
int		check_rev_order(t_data *data);

void	sort_for_b(t_data *data, int a);
void	sort_for_a(t_data *data, int a);

void	get_index(t_data *data);
int		find_index(int *a_arr, int len, int min);

#endif
