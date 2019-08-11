/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:57:37 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/19 18:57:42 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
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
	j = -1;
	while (++i < lens1)
		*(str + i) = *(s1 + i);
	free(s1);
	while (++j < lens2)
		*(str + i++) = *(s2 + j);
	free(s2);
	return (str);
}
