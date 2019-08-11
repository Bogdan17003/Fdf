/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:12:57 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/05 20:12:59 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len1;
	size_t	len2;
	size_t	inpl;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (len1 >= dstsize)
		return (dstsize + len2);
	if (dstsize - len1 - 1 >= len2)
		inpl = len2;
	else
		inpl = dstsize - len1 - 1;
	ft_memcpy(&dst[len1], src, inpl);
	dst[len1 + inpl] = '\0';
	return (len1 + len2);
}
