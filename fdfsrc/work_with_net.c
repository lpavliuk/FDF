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

static void	write_instuction(t_fdf *fdf)
{
	mlx_string_put(MLX, WIN, 0, 0, 0xFFFFFF, "------------------------\n");
	mlx_string_put(MLX, WIN, 0, 20, 0xFFFFFF, "|SCALE:       |'+', '-'|\n");
	mlx_string_put(MLX, WIN, 0, 40, 0xFFFFFF, "|----------------------|\n");
	mlx_string_put(MLX, WIN, 0, 60, 0xFFFFFF, "|TWIST:   x - |'1', '4'|\n");
	mlx_string_put(MLX, WIN, 0, 80, 0xFFFFFF, "|         y - |'2', '5'|\n");
	mlx_string_put(MLX, WIN, 0, 100, 0xFFFFFF, "|         z - |'3', '6'|\n");
	mlx_string_put(MLX, WIN, 0, 120, 0xFFFFFF, "|----------------------|\n");
	mlx_string_put(MLX, WIN, 0, 140, 0xFFFFFF, "|SHIFT:left - |   '<'  |\n");
	mlx_string_put(MLX, WIN, 0, 160, 0xFFFFFF, "|     right - |   '>'  |\n");
	mlx_string_put(MLX, WIN, 0, 180, 0xFFFFFF, "|        up - |   '^'  |\n");
	mlx_string_put(MLX, WIN, 0, 200, 0xFFFFFF, "|      down - |  down  |\n");
	mlx_string_put(MLX, WIN, 0, 220, 0xFFFFFF, "|----------------------|\n");
	mlx_string_put(MLX, WIN, 0, 240, 0xFFFFFF, "|COLORS: red -|   '2'  |\n");
	mlx_string_put(MLX, WIN, 0, 260, 0xFFFFFF, "|     yellow -|   '1'  |\n");
	mlx_string_put(MLX, WIN, 0, 280, 0xFFFFFF, "|      green -|   '3'  |\n");
	mlx_string_put(MLX, WIN, 0, 300, 0xFFFFFF, "|       blue -|   '4'  |\n");
	mlx_string_put(MLX, WIN, 0, 320, 0xFFFFFF, "|       aqua -|   '5'  |\n");
	mlx_string_put(MLX, WIN, 0, 340, 0xFFFFFF, "|       pink -|   '6'  |\n");
	mlx_string_put(MLX, WIN, 0, 360, 0xFFFFFF, "|      white -|   '0'  |\n");
	mlx_string_put(MLX, WIN, 0, 380, 0xFFFFFF, "|----------------------|\n");
	mlx_string_put(MLX, WIN, 0, 400, 0xFFFFFF, "|ESC          |  SPACE |\n");
	mlx_string_put(MLX, WIN, 0, 420, 0xFFFFFF, "------------------------\n");
}

void		also(t_fdf *fdf)
{
	if (!fdf->k)
		mlx_string_put(MLX, WIN, 0, 0, 0xFFFFFF, "PRESS 'SPACE': INSTUCTIONS");
	else
		write_instuction(fdf);
	RAD_X = 0;
	RAD_Y = 0;
	RAD_Z = 0;
}

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
	if (!xyz->next)
		mlx_pixel_put(MLX, WIN, PX(xyz->x, SIZE), PY(xyz->y, SIZE), COLOR);
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
