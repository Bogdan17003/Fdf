/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:05:44 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/07 18:05:47 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)ft_strnew(ft_strlen(s));
	if (str)
	{
		while (*(s + i))
		{
			*(str + i) = f(*(s + i));
			i++;
		}
		return (str);
	}
	return (0);
}
