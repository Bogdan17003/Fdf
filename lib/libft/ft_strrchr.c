/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:44:20 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/03 18:44:24 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cchr;
	char	*str;
	int		len;

	str = (char*)s;
	cchr = ft_strchr(str, c);
	if (c == '\0')
	{
		len = ft_strlen(str);
		str = str + len;
		return (str);
	}
	if (cchr != NULL)
	{
		while (*cchr)
		{
			if (*cchr == c)
				str = cchr;
			cchr++;
		}
		return (str);
	}
	return (0);
}
