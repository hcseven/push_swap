/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:49:02 by hseven            #+#    #+#             */
/*   Updated: 2022/10/02 19:49:02 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi( char *str)
{
	int				a;
	int				b;
	long long int	hesap;

	a = 0;
	b = 1;
	hesap = 0;
	while (str[a] == 32 || (str[a] >= '\t' && str[a] <= '\r'))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		hesap = (hesap * 10) + (str[a] - 48) * b;
		if (hesap > 2147483647)
			return (hesap);
		else if (hesap < -2147483648)
			return (hesap);
		a++;
	}
	return (hesap);
}

int	str_in_array(const char *s, char delimiter)
{
	int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy_ps(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}
