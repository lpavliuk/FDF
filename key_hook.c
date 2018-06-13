/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:07:27 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/12 18:07:29 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	work_with_xy(int keycode, t_coord *xyz)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (keycode == 124)
		x = 1;
	else if (keycode == 126)
		y = -1;
	else if (keycode == 123)
		x = -1;
	else
		y = 1;
	while (xyz)
	{
		xyz->x += x;
		xyz->y += y;
		xyz = xyz->next;
	}
}

static void	check_z(int keycode, t_coord *tmp, t_fdf *fdf)
{
	if (keycode == 83)
		RAD_X -= 0.05;
	else if (keycode == 84)
		RAD_Y -= 0.05;
	else if (keycode == 85)
		RAD_Z -= 0.05;
	else if (keycode == 86)
		RAD_X += 0.05;
	else if (keycode == 87)
		RAD_Y += 0.05;
	else if (keycode == 88)
		RAD_Z += 0.05;
	// else if (keycode == 69)
	// 	fdf->k++;
	// else if (keycode == 78)
	// 	fdf->k--;
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
}

int			key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (keycode == 124 || keycode == 126 ||
		keycode == 125 || keycode == 123)
		work_with_xy(keycode, XYZ);
	else if (keycode == 83 || keycode == 84 || keycode == 85
		|| keycode == 86 || keycode == 87 || keycode == 88
		|| keycode == 69 || keycode == 78)
		check_z(keycode, XYZ, fdf);
	mlx_clear_window(MLX, WIN);
	drawing_net(fdf, XYZ);
	RAD_X = 0;
	RAD_Y = 0;
	RAD_Z = 0;
	return (0);
}
