/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:15:46 by bdeomin           #+#    #+#             */
/*   Updated: 2018/10/29 19:15:49 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	lenstr;

	i = 0;
	lenstr = ft_strlen(src);
	while (i <= lenstr && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i > lenstr && i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
