/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:31:19 by hseven            #+#    #+#             */
/*   Updated: 2022/10/16 01:04:37 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isright(int c)
{
	if ((c <= '9' && c >= '0') || c == '-' || c == '+' || c == 32 || c == '\0')
		return (1);
	return (0);
}

int	ft_strlen(char const *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*str;
	int		b;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0')
	{
		str[a + b] = s2[b];
		b++;
	}
	str[a + b] = '\0';
	free (s1);
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	a = malloc(size * nitems);
	if (!a)
		return (0);
	while (nitems > i)
	{
		((unsigned char *)a)[i] = '\0';
		i++;
	}
	return (a);
}

size_t	ft_strlcpy_ps(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > a)
	{
		while (src[a] != '\0' && (size - 1) > a)
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	while (src[a] != '\0')
	{
		a++;
	}
	return (a);
}
