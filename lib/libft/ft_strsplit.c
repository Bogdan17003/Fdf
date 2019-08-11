/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:44:58 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/12 19:45:01 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_element_of_masive(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (*s != c && *s != '\0')
		n++;
	while (*(s + i))
	{
		if (*(s + i) != c && *(s + i - 1) == c)
			n++;
		i++;
	}
	return (n);
}

static char	*ft_fill_mem(char *str, char const *s, int mem, int i)
{
	int len;
	int j;

	j = 0;
	len = i - mem;
	while (mem > 0)
	{
		*(str + j) = *(s + len);
		j++;
		len++;
		mem--;
	}
	return (str);
}

static int	ft_kill_symbol(char const *s, int *i, char c)
{
	int n;

	n = 0;
	if (*(s + *i) == c && *(s + *i) != '\0')
	{
		*i = *i + 1;
		return (0);
	}
	while (*(s + *i) != c && *(s + *i) != '\0')
	{
		*i = *i + 1;
		n++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		mem;
	char	**str;

	if (!s || !(str = (char**)malloc(
		(ft_element_of_masive(s, c) + 1) * sizeof(char*))))
		return (0);
	i = 0;
	j = 0;
	mem = 0;
	while (*(s + i))
	{
		mem = ft_kill_symbol(s, &i, c);
		if (mem != 0)
		{
			str[j] = ft_strnew(mem);
			str[j] = ft_fill_mem(str[j], s, mem, i);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}
