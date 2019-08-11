/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:51:16 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/08 20:51:19 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
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
