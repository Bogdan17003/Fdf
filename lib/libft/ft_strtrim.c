/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:27:32 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/12 17:27:34 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numb_element(char const *s, int temp)
{
	int i;
	int j;

	i = 0;
	while (*(s + temp + i))
	{
		i++;
		j = 0;
		while (*(s + temp + i + j) == ' ' || *(s + temp + i + j) == '\n'
			|| *(s + temp + i + j) == '\t')
			j++;
		if (*(s + temp + i + j) != '\0')
			i = i + j;
		else
			return (i);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		temp;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	temp = i;
	i = numb_element(s, temp);
	str = ft_strnew(i);
	if (!str)
		return (0);
	ft_strncpy(str, &s[temp], i);
	return (str);
}
