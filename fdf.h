/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:30:18 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/11 16:30:20 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define ERR_0 "{red}ERROR: {yellow}incorrect input file!\n"
# define ERR_1 "{red}ERROR: {yellow}must be ONLY ONE argument!\n"
# define ERR_2 "{red}ERROR: {yellow}incorrect data in file!\n"

# define MLX fdf->mlx_ptr
# define WIN fdf->win_ptr
# define FD fdf->fd
# define LINE fdf->line
# define MAX_X fdf->max_x
# define MAX_Y fdf->max_y
# define NUM_X fdf->num_x
# define NUM_Y fdf->num_y
# define RAD_X fdf->rad_x
# define RAD_Y fdf->rad_y
# define RAD_Z fdf->rad_z
# define XYZ fdf->xyz

# define PI 3.14159265359

typedef struct	s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		max_x;
	int		max_y;
	int		num_x;
	int		num_y;
	double	rad_x;
	double	rad_y;
	double	rad_z;
	int		fd;
	char	*line;
	t_coord	*xyz;
}				t_fdf;

void			ft_error(char *error);
void			validation(t_fdf *fdf, t_coord *xyz);
int				key_hook(int keycode, t_fdf *fdf);
int				from_z_to_xy(t_coord *xyz, t_fdf *fdf);
// int				for_y(t_coord *xyz);
// int				for_z(t_coord *xyz, t_fdf *fdf);
void			drawing_net(t_fdf *fdf, t_coord *xyz);

#endif
