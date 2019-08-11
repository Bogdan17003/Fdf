/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:06:10 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 17:35:54 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_f_var(t_mlx *mlx, t_linepoint *coord, int color,
																t_step *steps)
{
	int			i;
	t_bresen	*perem;

	i = 0;
	if (!(perem = (t_bresen *)malloc(sizeof(t_bresen))))
		show_error();
	perem->d = (abs(coord->y1 - coord->y0) << 1) - abs(coord->x1 - coord->x0);
	perem->d1 = abs(coord->y1 - coord->y0) << 1;
	perem->d2 = (abs(coord->y1 - coord->y0) - abs(coord->x1 - coord->x0)) << 1;
	mlx_pixel_put(mlx->mlx, mlx->window, coord->x0, coord->y0, color);
	perem->x = coord->x0 + steps->sx;
	perem->y = coord->y0;
	while (++i <= abs(coord->x1 - coord->x0))
	{
		if (perem->d > 0)
		{
			perem->d += perem->d2;
			perem->y += steps->sy;
		}
		else
			perem->d += perem->d1;
		mlx_pixel_put(mlx->mlx, mlx->window, perem->x, perem->y, color);
		perem->x += steps->sx;
	}
	free(perem);
}

void			print_s_var(t_mlx *mlx, t_linepoint *coord, int color,
																t_step *steps)
{
	int			i;
	t_bresen	*perem;

	i = 0;
	if (!(perem = (t_bresen *)malloc(sizeof(t_bresen))))
		show_error();
	perem->d = (abs(coord->x1 - coord->x0) << 1) - abs(coord->y1 - coord->y0);
	perem->d1 = abs(coord->x1 - coord->x0) << 1;
	perem->d2 = (abs(coord->x1 - coord->x0) - abs(coord->y1 - coord->y0)) << 1;
	mlx_pixel_put(mlx->mlx, mlx->window, coord->x0, coord->y0, color);
	perem->y = coord->y0 + steps->sy;
	perem->x = coord->x0;
	while (++i <= abs(coord->y1 - coord->y0))
	{
		if (perem->d > 0)
		{
			perem->d += perem->d2;
			perem->x += steps->sx;
		}
		else
			perem->d += perem->d1;
		mlx_pixel_put(mlx->mlx, mlx->window, perem->x, perem->y, color);
		perem->y += steps->sy;
	}
	free(perem);
}
