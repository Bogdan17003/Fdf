/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:17:28 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/17 19:34:25 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			segment(t_mlx *mlx, t_linepoint *coord, int color)
{
	t_step		*steps;

	steps = (t_step *)malloc(sizeof(t_step));
	steps->sy = coord->y1 >= coord->y0 ? 1 : -1;
	steps->sx = coord->x1 >= coord->x0 ? 1 : -1;
	if (abs(coord->y1 - coord->y0) <= abs(coord->x1 - coord->x0))
		print_f_var(mlx, coord, color, steps);
	else
		print_s_var(mlx, coord, color, steps);
	free(steps);
}
