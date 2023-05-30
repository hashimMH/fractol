/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:02:55 by hmohamed          #+#    #+#             */
/*   Updated: 2023/02/21 14:26:44 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parc_fractol(char **str, int an, t_tv *tv)
{
	if (an > 1)
	{
		if (an == 2 && ft_strncmp("mandelbrot", str[1], 10) == 0)
			return (1);
		else if (an == 4 && ft_strncmp("julia", str[1], 5) == 0)
		{
			if (ft_atof(str[2]) <= 1.0 && ft_atof(str[3]) >= -1.0)
			{
				tv->jnx = ft_atof(str[2]);
				tv->jny = ft_atof(str[3]);
				return (2);
			}
		}
		else if (an == 2 && ft_strncmp("burningship", str[1], 11) == 0)
			return (3);
	}
	ft_putstr_fd("1:mandelbrot \n2:\
julia + first point + second point\n3:burningship\n", 2);
	exit(1);
}

void	drawone(t_fac *st)
{
	if (st->var->id == 1)
		manbord(1080, 1080, st);
	else if (st->var->id == 2)
		julia(1080, 1080, st);
	else if (st->var->id == 3)
		burningship(1080, 1080, st);
}
