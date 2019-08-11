/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:37:13 by bdeomin           #+#    #+#             */
/*   Updated: 2018/10/30 17:37:16 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*str;
	char	*ptr;

	str = (char *)haystack;
	ptr = (char *)needle;
	if (ptr[0] == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == ptr[i])
		{
			i++;
			if (ptr[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
