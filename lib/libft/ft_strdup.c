/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:56:04 by bdeomin           #+#    #+#             */
/*   Updated: 2018/10/29 19:56:06 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenstr;
	int		i;
	char	*strc;

	i = 0;
	lenstr = ft_strlen(s1);
	strc = (char *)malloc(lenstr + 1);
	if (strc == 0)
		return (0);
	while (s1[i])
	{
		strc[i] = s1[i];
		i++;
	}
	strc[i] = '\0';
	return (strc);
}
