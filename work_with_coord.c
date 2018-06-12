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

int	from_z_to_xy(t_coord *xyz, t_fdf *fdf)
{
	double	x[2];
	double	y[2];
	double	z[2];

	while (xyz)
	{
		x[0] = xyz->x;
    	y[0] = xyz->y * cos(RAD_X) + xyz->z * sin(RAD_X);
    	z[0] = xyz->z * cos(RAD_X) - xyz->y * sin(RAD_X);

    	x[1] = x[0] * cos(RAD_Y) - z[0] * sin(RAD_Y);
    	y[1] = y[0];
		xyz->z = z[0] * cos(RAD_Y) + x[0] * sin(RAD_Y);

		xyz->x = -x[1] * cos(RAD_Z) + y[1] * sin(RAD_Z);
   		xyz->y = y[1] * cos(RAD_Z) - x[1] * sin(RAD_Z);

		xyz = xyz->next;
	}
	return (0);
}

// int	for_z(t_coord *xyz)
// {
// 	int		rad;
// 	int		z;
// 	int		y;
// 	t_coord	*tmp;

// 	tmp = xyz;
// 	while (xyz)
// 	{
// 		y = xyz->y;
// 		z = xyz->z;
// 		rad = xyz->x + 1 * PI/180;
// 		xyz->y = (y * cos(rad)) + (z * sin(rad));
// 		xyz->z = (-y * cos(rad)) + (z * sin(rad));
// 		xyz = xyz->next;
// 	}
// 	return (0);
// }
