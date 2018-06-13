/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:25:18 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/12 16:25:19 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	for_x(t_coord *xyz, t_fdf *fdf)
{
	double	y;
	double	z;

	y = fdf->prev_y;
	z = fdf->prev_z;
	xyz->y = (y * cos(RAD_X)) + (z * sin(RAD_X));
	xyz->z = (-y * sin(RAD_X)) + (z * cos(RAD_X));
}

void	for_y(t_coord *xyz, t_fdf *fdf)
{
	double	x;

	x = fdf->prev_x;
	xyz->x = (x * cos(RAD_Y)) + (xyz->z * sin(RAD_Y));
	xyz->z = (-x * sin(RAD_Y)) + (xyz->z * cos(RAD_Y));
}

void	for_z(t_coord *xyz, t_fdf *fdf)
{
	double	x;

	x = xyz->x;
	xyz->x = (x * cos(RAD_Z)) - (xyz->y * sin(RAD_Z));
	xyz->y = (x * sin(RAD_Z)) + (xyz->y * cos(RAD_Z));
}
