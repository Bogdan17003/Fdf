/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinlenfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:56:12 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/20 17:56:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinlenfree(char *s1, char *s2, int lens1, int lens2)
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
	j = -1;
	while (++i < lens1)
		*(str + i) = *(s1 + i);
	free(s1);
	while (++j < lens2)
		*(str + i++) = *(s2 + j);
	free(s2);
	return (str);
}
