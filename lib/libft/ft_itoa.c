/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:01:24 by bdeomin           #+#    #+#             */
/*   Updated: 2018/11/12 20:01:26 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_string(char *str, int i, long cn)
{
	if (cn == 0)
		*(str) = '0';
	while (cn)
	{
		*(str + i) = (cn % 10) + '0';
		cn /= 10;
		i--;
	}
}

char		*ft_itoa(int n)
{
	int				i;
	long			cn;
	char			*str;

	i = 1;
	cn = n;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	str = ((n < 0) ? (char*)ft_strnew(i + 1) : (char*)ft_strnew(i));
	if (!str)
		return (0);
	if (n > 0)
		i--;
	if (cn < 0)
	{
		*str = '-';
		cn *= (-1);
	}
	ft_string(str, i, cn);
	return (str);
}
