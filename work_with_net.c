/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_net.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:33:16 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/11 19:33:17 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	from_z_to_xy(t_fdf *fdf, t_coord *xyz)
{
	int		x;
	int		y;
	t_coord	*tmp;

	tmp = xyz;
	while (xyz)
	{
		x = xyz->x;
		y = xyz->y;
		xyz->x = ((x * cos(xyz->z)) + (y * sin(xyz->z))) * 1000/2/NUM_X + 250;
		xyz->y = ((y * cos(xyz->z)) - (x * sin(xyz->z))) * 1000/2/NUM_Y + 250;
		xyz = xyz->next;
	}
	while (tmp)
	{
		if (!MAX_X || MAX_X < tmp->x)
			MAX_X = tmp->x;
		if (!MAX_Y || MAX_Y < tmp->y)
			MAX_Y = tmp->y;
		tmp = tmp->next;
	}
}

void		write_line(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
 	int dx; 
 	int dy;
 	int	sx;
 	int	sy;
 	int err;
 	int	e2;
 
 	dx = abs(x1-x0);
 	dy = abs(y1-y0);
 	sx = (x0 < x1) ? 1 : -1;
 	sy = (y0 < y1) ? 1 : -1;
 	err = ((dx > dy) ? dx : -dy)/2; 
 	while (x0 != x1 && y0 != y1)
 	{
    	mlx_pixel_put(MLX, WIN, x0, y0, 0xFFFFFF);
    	mlx_pixel_put(MLX, WIN, y0, x0, 0xFFFFFF);
    	e2 = err;
    	if (e2 > -dx)
    	{
    		err -= dy;
    		x0 += sx;
    	}
    	if (e2 < dy)
    	{
    		err += dx;
    		y0 += sy;
    	}
    }
  }

void		drawing_net(t_fdf *fdf, t_coord *xyz)
{
	int		x;
	int		y;
	t_coord *tmp;

	tmp = xyz;
	while (xyz)
	{
		x = xyz->x;
		y = xyz->y;
		if (xyz->next)
			write_line(fdf, x, y, xyz->next->x, xyz->next->y);
		xyz = xyz->next;
	}
}
