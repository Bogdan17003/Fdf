/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:55:37 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/07 21:55:40 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			*(str + i) = f(i, *(s + i));
			i++;
		}
		return (str);
	}
	return (0);
}
