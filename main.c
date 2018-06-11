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
}
/**********************************************/

static int	exit_x(int keycode)
{
	exit(0);
}

void	ft_error(char *error)
{
	ft_printf(error);
	exit(0);
}

int		main(int argc, char **argv)
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
	FD = 0;
	LINE = NULL;
	if (argc == 1 || argc > 2)
		ft_error(ERR_1);
	if ((FD = open(argv[1], O_RDONLY)) < 1)
		ft_error(ERR_0);
	validation(fdf, xyz);
	show_list(fdf, xyz);
	// system("leaks a.out");
	return (0);
}