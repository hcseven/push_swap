/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:43:49 by hseven            #+#    #+#             */
/*   Updated: 2022/10/15 02:28:57 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data{
	int	len_a;
	int	len_b;
	int	len_i;
	int	*a_arr;
	int	*b_arr;
	int	*i_arr;
	int	size;
	int	step_count;
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

void	b_r_rotate_b(t_data *data);
void	b_r_rotate_a(t_data *data);
void	b_rotate_b(t_data *data);
void	b_rotate_a(t_data *data);
void	b_rotate_r(t_data *data, int a);

void	b_push_a(t_data *data);
void	b_push_b(t_data *data);
void	b_swap_a(t_data *data);
void	b_swap_b(t_data *data);
void	b_swap_ab(t_data *data);

int		read_input(t_data *data);
int		input_check(t_data *data, char *s);
void	input_use(t_data *data, char *s);
void	ft_check_sort(t_data *data);

#endif