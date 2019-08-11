/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:04:28 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 17:42:27 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_linepoint		*input(int x0, int y0, int x1, int y1)
{
	t_linepoint	*coordination;

	if (!(coordination = (t_linepoint *)malloc(sizeof(t_linepoint))))
		show_error();
	coordination->x0 = x0;
	coordination->y0 = y0;
	coordination->x1 = x1;
	coordination->y1 = y1;
	return (coordination);
}

void			continued(t_mlx *mlx, t_map *map)
{
	int			i;
	int			j;
	t_linepoint	*c;

	i = -1;
	while (++i < map->len_horizontal)
	{
		j = -1;
		while (++j < map->len_vertical - 1)
		{
			c = input(map->points[j][i].x, map->points[j][i].y,
				map->points[j + 1][i].x, map->points[j + 1][i].y);
			segment(mlx, c, 0xFFFFFF);
			free(c);
		}
	}
}

void			printmap(t_mlx *mlx, t_map *map)
{
	int			i;
	int			j;
	t_linepoint	*c;

	i = -1;
	while (++i < map->len_vertical)
	{
		j = -1;
		while (++j < map->len_horizontal - 1)
		{
			c = input(map->points[i][j].x, map->points[i][j].y,
				map->points[i][j + 1].x, map->points[i][j + 1].y);
			segment(mlx, c, 0xFFFFFF);
			free(c);
		}
	}
	continued(mlx, map);
}

void			rotation(t_map **map)
{
	t_newpoints **coord;
	int			i;

	i = -1;
	if (!(coord = (t_newpoints **)malloc((*map)->len_vertical *
													sizeof(t_newpoints *))))
		show_error();
	while (++i < (*map)->len_vertical)
		coord[i] = (t_newpoints *)ft_memalloc((*map)->len_horizontal *
														sizeof(t_newpoints));
	moving_about_start(&(*map));
	new_coord(*map, coord);
	other_coordination_x(&(*map), coord);
	other_coordination_y(&(*map), coord);
	i = -1;
	while (++i < (*map)->len_vertical)
		free(coord[i]);
	free(coord);
	moving_about_standart(&(*map));
}

void			drawmap(t_map **map)
{
	t_mlx	*mlx;
	int		i;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		show_error();
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, 2000, 1200, "fdf");
	rotation(&(*map));
	printmap(mlx, *map);
	i = -1;
	while (++i < (*map)->len_vertical)
		free((*map)->points[i]);
	free((*map)->points);
	free(*map);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_loop(mlx->mlx);
}
