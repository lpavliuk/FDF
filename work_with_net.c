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

void		write_line(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
 	int 	dx; 
 	int 	dy;
 	int		sx;
 	int		sy;
 	int 	err;
 	int		e2;
 
 	dx = abs(x1 - x0);
 	dy = abs(y1 - y0);
 	ft_printf("%d\n", x0);
 	sx = (x0 < x1) ? 1 : -1;
 	sy = (y0 < y1) ? 1 : -1;
 	err = ((dx > dy) ? dx : -dy) / 2;
 	ft_printf("%d\n", err);
 	while (1)
 	{
    	mlx_pixel_put(MLX, WIN, x0, y0, 0xFFFFFF);
    	if (x0 == x1 && y0 == y1)
    		break ;
    	e2 = err;
    	if (e2 > -dx)
    	{
    		err -= dy;
    		x0 = x0 + sx;
    	}
    	if (e2 < dy)
    	{
    		err += dx;
    		y0 = y0 + sy;
    	}
    }
  }

void		drawing_net(t_fdf *fdf, t_coord *xyz)
{
	int		i;
	int		n;
	t_coord *tmp;

	n = 0;
	// from_z_to_xy(xyz, fdf);
	tmp = xyz;
	while (tmp)
	{
		fdf->prev_x = tmp->x;
		fdf->prev_y = tmp->y;
		fdf->prev_z = tmp->z;
		for_x(tmp, fdf);
		for_y(tmp, fdf);
		for_z(tmp, fdf);
		tmp = tmp->next;
	}
	show_list(fdf, xyz);
	while (xyz)
	{
		i = NUM_X;
		tmp = xyz->next;
		if (xyz->next && n < NUM_X - 1)
		{
			// ft_printf("y: %d\ntmp->y: %d\n", y, tmp->y);
			// show_list(fdf, xyz);
			write_line(fdf, (int)PX(xyz->x), (int)PY(xyz->y), (int)PX(xyz->next->x), (int)PY(xyz->next->y));
		}
		while (tmp && i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		if (n == NUM_X - 1)
			n = 0;
		else
			n++;
		if (tmp && i == 1)
			write_line(fdf, (int)PX(xyz->x), (int)PY(xyz->y), (int)PX(tmp->x), (int)PY(tmp->y));
		xyz = xyz->next;
	}
}
