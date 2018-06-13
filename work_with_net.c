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

void		write_line(t_fdf *fdf, t_coord *xyz, int x1, int y1)
{
	X0 = (int)PX(xyz->x, SIZE);
	Y0 = (int)PY(xyz->y, SIZE);
	fdf->dx = abs(x1 - X0);
	fdf->dy = abs(y1 - Y0);
	fdf->sx = (X0 < x1) ? 1 : -1;
	fdf->sy = (Y0 < y1) ? 1 : -1;
	fdf->err = ((fdf->dx > fdf->dy) ? fdf->dx : -fdf->dy) / 2;
	while (1)
	{
		mlx_pixel_put(MLX, WIN, X0, Y0, COLOR);
		if (X0 == x1 && Y0 == y1)
			break ;
		fdf->e2 = fdf->err;
		if (fdf->e2 > -fdf->dx)
		{
			fdf->err -= fdf->dy;
			X0 = X0 + fdf->sx;
		}
		if (fdf->e2 < fdf->dy)
		{
			fdf->err += fdf->dx;
			Y0 = Y0 + fdf->sy;
		}
	}
}

void		drawing_net(t_fdf *fdf, t_coord *xyz)
{
	int		i;
	int		n;
	t_coord *tmp;

	n = 0;
	if (SIZE < 0)
		SIZE = 0;
	while (xyz)
	{
		i = NUM_X + 1;
		tmp = xyz->next;
		if (xyz->next && n < NUM_X - 1)
			write_line(fdf, xyz,
				(int)PX(xyz->next->x, SIZE), (int)PY(xyz->next->y, SIZE));
		while (tmp && --i > 1)
			tmp = tmp->next;
		if (n == NUM_X - 1)
			n = 0;
		else
			n++;
		if (tmp && i == 1)
			write_line(fdf, xyz,
				(int)PX(tmp->x, SIZE), (int)PY(tmp->y, SIZE));
		xyz = xyz->next;
	}
}
