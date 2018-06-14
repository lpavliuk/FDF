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

static void	change_color(int keycode, t_fdf *fdf)
{
	int		x;
	t_coord	*tmp;

	tmp = XYZ;
	if (keycode == 29)
		x = 16777215;
	else if (keycode == 18)
		x = 16776960;
	else if (keycode == 19)
		x = 16711680;
	else if (keycode == 20)
		x = 65280;
	else if (keycode == 21)
		x = 255;
	else if (keycode == 22)
		x = 16711935;
	else if (keycode == 23)
		x = 65535;
	while (tmp)
	{
		tmp->color = x;
		tmp = tmp->next;
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

static void	instuctions(t_fdf *fdf)
{
	if (!fdf->k)
		fdf->k = 1;
	else
		fdf->k = 0;
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
		|| keycode == 86 || keycode == 87 || keycode == 88)
		check_z(keycode, XYZ, fdf);
	else if (keycode == 69)
		SIZE += 100;
	else if (keycode == 78)
		SIZE -= 100;
	else if ((keycode >= 18 && keycode <= 23) || keycode == 29
		|| keycode == 27 || keycode == 24)
		change_color(keycode, fdf);
	else if (keycode == 49)
		instuctions(fdf);
	mlx_clear_window(MLX, WIN);
	drawing_net(fdf, XYZ);
	also(fdf);
	return (0);
}
