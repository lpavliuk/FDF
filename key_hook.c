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

// static void	to_z(t_coord *xyz, char add)
// {
// 	if (add)
// 	{
// 		while (xyz)
// 		{
// 			xyz->z *= 1.1;
// 			xyz = xyz->next;
// 		}
// 	}
// 	else
// 	{
// 		while (xyz)
// 		{
// 			xyz->z *= 0.9;
// 			xyz = xyz->next;
// 		}
// 	}
// }

static void	change_color(int keycode, t_fdf *fdf)
{
	if (keycode == 29)
		COLOR = 16777215;
	else if (keycode == 18)
		COLOR = 16776960;
	else if (keycode == 19)
		COLOR = 16711680;
	else if (keycode == 20)
		COLOR = 65280;
	else if (keycode == 21)
		COLOR = 255;
	else if (keycode == 22)
		COLOR = 16711935;
	else if (keycode == 23)
		COLOR = 65535;
	// else if (keycode == 27)
	// 	to_z(XYZ, 1);
	// else if (keycode == 24)
	// 	to_z(XYZ, 0);
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
	mlx_clear_window(MLX, WIN);
	drawing_net(fdf, XYZ);
	RAD_X = 0;
	RAD_Y = 0;
	RAD_Z = 0;
	return (0);
}
