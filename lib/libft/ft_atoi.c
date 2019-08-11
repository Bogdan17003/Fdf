/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:49:11 by bdeomin           #+#    #+#             */
/*   Updated: 2018/10/25 19:49:16 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				znak;
	unsigned int	summ;

	znak = 1;
	i = 0;
	summ = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i++] == '-')
		znak = -1;
	else if (str[i - 1] != '+')
		i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((summ > 2147483647 && znak == 1) ||
			(summ > 2147483648 && znak == -1))
			return ((znak < 0) ? 0 : -1);
		summ = summ * 10 + (str[i] - '0');
		i++;
	}
	return (summ * znak);
}
