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
		ft_printf("x: %d, y: %d, z: %d\n", xyz->x, xyz->y, xyz->z);
		xyz = xyz->next;
	}
	ft_printf("Num x: %d\nNum y: %d\n", NUM_X, NUM_Y);
}
/**********************************************/

static int	exit_x(int keycode)
{
	exit(0);
}

void		ft_error(char *error)
{
	ft_printf(error);
	exit(0);
}

static int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	return (0);
}

static void	draw_net(t_fdf *fdf, t_coord *xyz)
{
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "FDF");
	drawing_net(fdf, xyz);
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
	if (argc == 1 || argc > 2)
		ft_error(ERR_1);
	if ((FD = open(argv[1], O_RDONLY)) < 1)
		ft_error(ERR_0);
	validation(fdf, xyz);
	from_z_to_xy(fdf, xyz);
	draw_net(fdf, xyz);
	show_list(fdf, xyz);
	// system("leaks fdf");
	return (0);
}
