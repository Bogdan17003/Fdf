/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:00 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 19:47:35 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		search_other_chars(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '+' && *str != '-' &&
													(*str < '0' || *str > '9'))
			return (1);
		if ((*str == '+' || *str == '-') && (*(str + 1) < '0' ||
													*(str + 1) > '9'))
			return (1);
		str++;
	}
	return (0);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
