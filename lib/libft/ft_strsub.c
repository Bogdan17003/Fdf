/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:04:38 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/07 23:04:40 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = 0;
	if (!s)
		return (0);
	if (len <= ft_strlen(s))
		str = (char *)ft_strnew(len);
	if (str)
	{
		while ((len--) > 0)
		{
			*(str + i) = *(s + start);
			i++;
			start++;
		}
		return (str);
	}
	return (0);
}
