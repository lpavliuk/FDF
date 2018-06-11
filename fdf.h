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

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define ERR_0 "ERROR: incorrect input file!\n"
# define ERR_1 "ERROR: must be ONLY ONE argument!\n"

# define FD fdf->fd

typedef struct	s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_fdf
{
	int fd;
}				t_fdf
#endif
