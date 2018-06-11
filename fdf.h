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

# define FD fdf->fd
# define LINE fdf->line

typedef struct	s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_fdf
{
	int		fd;
	char	*line;
}				t_fdf;

void			ft_error(char *error);
void			validation(t_fdf *fdf, t_coord *xyz);

#endif
