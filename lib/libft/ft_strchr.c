/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:44:12 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/03 18:44:14 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	if (c == '\0')
	{
		len = ft_strlen(ptr);
		ptr = ptr + len;
		return (ptr);
	}
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (0);
}
