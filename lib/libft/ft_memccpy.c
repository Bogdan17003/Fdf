/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:01:03 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/03 14:01:17 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n)
	{
		if (*ptr2 == (unsigned char)c)
		{
			*(ptr1++) = *(ptr2++);
			return (ptr1);
		}
		*(ptr1++) = *(ptr2++);
		n--;
	}
	return (NULL);
}
