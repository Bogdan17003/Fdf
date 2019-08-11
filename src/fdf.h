/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:49:50 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 18:26:03 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

typedef	struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct	s_points
{
	int			x;
	int			y;
	int			z;
}				t_points;

typedef	struct	s_map
{
	int			len_vertical;
	int			len_horizontal;
	int			start_x;
	int			start_y;
	t_points	**points;
}				t_map;

typedef struct	s_newpoints
{
	int			x;
	int			y;
	int			z;
}				t_newpoints;

typedef	struct	s_bresen
{
	int			d;
	int			d1;
	int			d2;
	int			x;
	int			y;
}				t_bresen;

typedef	struct	s_linepoint
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_linepoint;

typedef	struct	s_step
{
	int			sx;
	int			sy;
}				t_step;

int				search_other_chars(char *str);

int				hook_keydown(int key, t_mlx *mlx);

void			segment(t_mlx *mlx, t_linepoint *coord, int color);

void			moving_about_start(t_map **map);
void			moving_about_standart(t_map **map);

void			new_coord(t_map *map, t_newpoints **coord);

void			other_coordination_x(t_map **map, t_newpoints **coord);
void			other_coordination_y(t_map **map, t_newpoints **coord);
void			other_coordination_z(t_map **map, t_newpoints **coord);

void			print_f_var(t_mlx *mlx, t_linepoint *coord, int color,
																t_step *steps);

void			print_s_var(t_mlx *mlx, t_linepoint *coord, int color,
																t_step *steps);

void			reading_file(int fd, t_map **map);

void			show_error(void);

int				first_read(int fd, t_map **map);

int				count_tab(char *str);

void			malloc_memory(t_map **map);

void			drawmap(t_map **map);

#endif
