/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:38:24 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/19 18:38:27 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinlen(char const *s1, char const *s2, int lens1, int lens2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_strnew(lens1 + lens2);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (++i < lens1)
		*(str + i) = *(s1 + i);
	while (j < lens2)
	{
		*(str + i) = *(s2 + j);
		j++;
		i++;
	}
	return (str);
}
