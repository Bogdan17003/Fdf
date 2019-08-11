/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:10:51 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/17 19:13:44 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			new_coord(t_map *map, t_newpoints **coord)
{
	int i;
	int j;

	i = -1;
	while (++i < map->len_vertical)
	{
		j = -1;
		while (++j < map->len_horizontal)
		{
			coord[i][j].x = map->points[i][j].x;
			coord[i][j].y = map->points[i][j].y;
			coord[i][j].z = map->points[i][j].z;
		}
	}
}

void			other_coordination_x(t_map **map, t_newpoints **coord)
{
	int i;
	int j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = coord[i][j].x;
			(*map)->points[i][j].y = coord[i][j].y * cos(M_PI * 30 / 180) +
										coord[i][j].z * sin(M_PI * 30 / 180);
			(*map)->points[i][j].z = -(coord[i][j].y) * sin(M_PI * 30 / 180) +
										coord[i][j].z * cos(M_PI * 30 / 180);
		}
	}
	new_coord(*map, coord);
}

void			other_coordination_y(t_map **map, t_newpoints **coord)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = coord[i][j].x * cos(M_PI * 45 / 180) +
										coord[i][j].z * sin(M_PI * 45 / 180);
			(*map)->points[i][j].y = coord[i][j].y;
			(*map)->points[i][j].z = -(coord[i][j].x) * sin(M_PI * 45 / 180) +
										coord[i][j].z * cos(M_PI * 45 / 180);
		}
	}
	new_coord(*map, coord);
}

void			other_coordination_z(t_map **map, t_newpoints **coord)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = coord[i][j].x * cos(M_PI * 90 / 180) -
										coord[i][j].y * sin(M_PI * 90 / 180);
			(*map)->points[i][j].y = -(coord[i][j].x) * sin(M_PI * 90 / 180) +
										coord[i][j].y * cos(M_PI * 90 / 180);
			(*map)->points[i][j].z = coord[i][j].z;
		}
	}
	new_coord(*map, coord);
}
