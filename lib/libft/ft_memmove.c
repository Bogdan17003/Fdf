/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:02:37 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/03 14:02:41 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr1 > ptr2)
		while (len > 0)
		{
			ptr1[len - 1] = ptr2[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	return (ptr1);
}
