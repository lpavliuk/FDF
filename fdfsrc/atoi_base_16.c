/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:49:35 by opavliuk          #+#    #+#             */
/*   Updated: 2018/06/14 10:49:37 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_add_to_atoi(const char *str, int i, int num)
{
	int		c;
	int		base_16;
	int		n;
	char	*base;

	base = "0123456789ABCDEF";
	base_16 = 1;
	c = 6 - i;
	while (c > 0)
	{
		base_16 = base_16 * 16;
		c--;
	}
	if (str[i] >= '0' && str[i] <= '9')
		num = num + ((str[i] - '0') * base_16);
	else
	{
		n = 0;
		while (base[n] != str[i])
			n++;
		num = num + (n * base_16);
	}
	return (num);
}

int			ft_atoi_base_16(const char *str)
{
	int			x;
	size_t		i;
	long long	num;

	x = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			&& str[i] != '\0')
		i++;
	(str[i] == '-') ? x = -1 : 0;
	(str[i] == '+' || str[i] == '-') ? i++ : 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		num = ft_add_to_atoi(str, i, num);
		i++;
	}
	(num < 0 && x == -1) ? num = 0 : 0;
	(num < 0 && x == 1) ? num = -1 : 0;
	return ((int)(num * x));
}
