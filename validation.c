/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:32:42 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/11 17:32:44 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*lstnew(t_coord *xyz)
{
	while (xyz->next)
		xyz = xyz->next;
	xyz->next = malloc(sizeof(t_coord));
	xyz->next->x = 0;
	xyz->next->y = 0;
	xyz->next->z = 0;
	xyz->next->color = 16777215;
	xyz->next->next = NULL;
	return (xyz->next);
}

static void		check_color(t_coord *xyz, char *str)
{
	int i;

	i = 2;
	if (str[0] != '0')
		ft_error(ERR_4);
	if (str[1] != 'x')
		ft_error(ERR_4);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] < 'A' && str[i] > 'F')
			ft_error(ERR_4);
		i++;
	}
	if (i > 8)
		ft_error(ERR_4);
	COLOR = ft_atoi_base_16(&str[2]);
}

static void		check_str(t_coord *xyz, char *str)
{
	int i;
	int	minus;
	int	plus;

	i = 0;
	minus = 0;
	plus = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' &&
			str[i] != '+' && str[i] != ',')
			ft_error(ERR_3);
		else if (str[i] == '-')
			minus++;
		else if (str[i] == '+')
			plus++;
		else if (str[i] == ',')
		{
			check_color(xyz, &str[i + 1]);
			return ;
		}
		i++;
		if (minus > 1 || plus > 1 || (minus && plus))
			ft_error(ERR_3);
	}
}

static int		write_coord(t_fdf *fdf, t_coord *xyz, int i)
{
	int		n;
	char	**str;
	t_coord *tmp;

	n = 0;
	str = ft_strsplit(LINE, ' ');
	if (xyz->next)
		xyz = lstnew(xyz);
	while (str[n] != 0)
	{
		check_str(xyz, str[n]);
		xyz->x = (float)n;
		xyz->y = (float)i;
		xyz->z = (float)ft_atoi(str[n]);
		n++;
		if (str[n])
			xyz = lstnew(xyz);
	}
	ft_stralldel(str, n);
	free(str);
	return (n);
}

void			validation(t_fdf *fdf, t_coord *xyz)
{
	int i;
	int	num_of_coord;

	num_of_coord = 0;
	i = 0;
	get_next_line(FD, &LINE);
	num_of_coord = write_coord(fdf, xyz, i);
	i++;
	free(LINE);
	while (get_next_line(FD, &LINE) > 0)
	{
		if (write_coord(fdf, xyz, i) != num_of_coord)
			ft_error(ERR_2);
		i++;
		free(LINE);
	}
	NUM_X = num_of_coord;
	NUM_Y = i;
}
