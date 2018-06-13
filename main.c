/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:28:31 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/11 16:28:32 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*****************SHOW LIST!*******************/

void		show_list(t_fdf *fdf, t_coord *xyz)
{
	while (xyz)
	{
		printf("x: %f, y: %f, z: %f\n", xyz->x, xyz->y, xyz->z);
		xyz = xyz->next;
	}
	ft_printf("Num x: %d\nNum y: %d\n", NUM_X, NUM_Y);
}
/**********************************************/

void		ft_error(char *error)
{
	ft_printf(error);
	exit(0);
}

static int	exit_x(int keycode)
{
	exit(0);
}

static void	draw_net(t_fdf *fdf, t_coord *xyz)
{
	t_coord *tmp;

	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1920, 1080, "FDF");
	tmp = xyz;
	while (tmp)
	{
		fdf->prev_x = tmp->x;
		fdf->prev_y = tmp->y;
		fdf->prev_z = tmp->z * 0.5;
		for_x(tmp, fdf);
		for_y(tmp, fdf);
		for_z(tmp, fdf);
		tmp = tmp->next;
	}
	drawing_net(fdf, xyz);
	RAD_X = 0;
	RAD_Y = 0;
	RAD_Z = 0;
	mlx_hook(WIN, 2, 0, key_hook, fdf);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
}

int			main(int argc, char **argv)
{
	int		i;
	t_coord *xyz;
	t_fdf	*fdf;

	i = 0;
	xyz = malloc(sizeof(t_coord));
	xyz->x = 0;
	xyz->y = 0;
	xyz->z = 0;
	xyz->next = NULL;
	fdf = malloc(sizeof(t_fdf));
	MLX = NULL;
	WIN = NULL;
	FD = 0;
	LINE = NULL;
	MAX_X = 0;
	MAX_Y = 0;
	NUM_X = 0;
	NUM_Y = 0;
	RAD_X = -0.01;
	RAD_Y = -0.15;
	RAD_Z = 0.5;
	fdf->prev_x = 0;
	fdf->prev_y = 0;
	fdf->prev_z = 0;
	fdf->k = 1;
	fdf->dx = 0;
	fdf->dy = 0;
	fdf->sx = 0;
	fdf->sy = 0;
	fdf->err = 0;
	fdf->e2 = 0;
	fdf->x0 = 0;
	fdf->y0 = 0;
	SIZE = 1000;
	XYZ = xyz;
	COLOR = 16777215;
	if (argc == 1 || argc > 2)
		ft_error(ERR_1);
	if ((FD = open(argv[1], O_RDONLY)) < 1 || read(FD, &LINE, 0) < 0)
		ft_error(ERR_0);
	validation(fdf, xyz);
	draw_net(fdf, xyz);
	return (0);
}
