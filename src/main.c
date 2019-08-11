/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:48:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 19:48:05 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_SUCCESS);
}

void	malloc_memory(t_map **map)
{
	int	i;

	i = -1;
	if (!((*map)->points = (t_points **)malloc((*map)->len_vertical *
														sizeof(t_points*))))
	{
		free(*map);
		show_error();
	}
	while (++i < (*map)->len_vertical)
		if (!((*map)->points[i] = (t_points *)ft_memalloc((*map)->len_horizontal
			* sizeof(t_points))))
		{
			while (i--)
				free((*map)->points[i]);
			free(*map);
		}
}

void	place_points(t_map **map)
{
	int i;
	int j;

	i = -1;
	while (++i < (*map)->len_vertical)
	{
		j = -1;
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].x = (*map)->start_x + 15 * j;
			(*map)->points[i][j].y = (*map)->start_y + 15 * i;
		}
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_map		*map;

	if (argc != 2)
		show_error();
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		show_error();
	map->len_vertical = 0;
	map->len_horizontal = 0;
	if (first_read(fd = open(argv[1], O_RDONLY), &map))
	{
		free(map);
		show_error();
	}
	close(fd);
	map->len_horizontal++;
	malloc_memory(&map);
	fd = open(argv[1], O_RDONLY);
	reading_file(fd, &map);
	close(fd);
	map->start_x = 100;
	map->start_y = 50;
	place_points(&map);
	drawmap(&map);
	return (0);
}
