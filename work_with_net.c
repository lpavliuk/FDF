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

void		drawing_net(t_fdf *fdf, t_coord *xyz)
{
	int		x;
	int		y;
	int		a;

	x = xyz->x;
	y = xyz->y;
	a = 1;
	while (x < MAX_X)
		mlx_pixel_put(MLX, WIN, x++, y, 0xFFFFFF);
	x = xyz->x;
	while (y < MAX_Y)
		mlx_pixel_put(MLX, WIN, x, y++, 0xFFFFFF);
}
