/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbubble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:07:36 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/19 17:07:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sortbubble(char *str)
{
	int		i;
	int		j;
	int		n;
	char	elem;

	i = -1;
	n = ft_strlen(str);
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
			if (str[j] > str[j + 1])
			{
				elem = str[j];
				*(str + j) = *(str + j + 1);
				*(str + j + 1) = elem;
			}
	}
	return (str);
}
