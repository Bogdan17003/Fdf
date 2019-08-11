/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:13:53 by bdeomin           #+#    #+#             */
/*   Updated: 2018/10/30 18:13:57 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;
	size_t	j;

	j = 0;
	hay = (char *)haystack;
	need = (char *)needle;
	if (*need == '\0' || need == hay)
		return (hay);
	while (*(hay + j) && (j < len))
	{
		i = 0;
		while (*(hay + j) && *(need + i) &&
		(*(hay + j) == *(need + i)) && (j < len))
		{
			i++;
			j++;
			if (*(need + i) == '\0')
				return (hay + (j - i));
		}
		j = j - i + 1;
	}
	return (0);
}
