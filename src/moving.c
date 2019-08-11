/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:11:41 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 17:43:41 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			moving_about_start(t_map **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = (*map)->points[i][j].x - (*map)->start_x -
												15 * (*map)->len_horizontal / 2;
			(*map)->points[i][j].y = (*map)->points[i][j].y - (*map)->start_y -
												15 * (*map)->len_vertical / 2;
		}
	}
}

void			moving_about_standart(t_map **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = (*map)->points[i][j].x + (*map)->start_x +
												15 * (*map)->len_horizontal / 2;
			(*map)->points[i][j].y = (*map)->points[i][j].y + (*map)->start_y +
												15 * (*map)->len_vertical / 2;
		}
	}
}
