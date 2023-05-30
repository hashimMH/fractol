/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:35:58 by hmohamed          #+#    #+#             */
/*   Updated: 2023/02/06 17:54:27 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int xs, int ys, t_fac *st)
{
	st->var->row = 0;
	while (st->var->row < xs)
	{
		st->var->col = 0;
		while (st->var->col < ys)
		{
			st->var->c_re = st->var->jnx;
			st->var->c_im = st->var->jny;
			st->var->x = ((st->var->col - xs / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->mx;
			st->var->y = ((st->var->row - ys / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->my;
			st->var->iteration = 0;
			drawmandel(st->var, st->img);
		st->var->col++;
		}
		st->var->row++;
	}
	mlx_put_image_to_window(st->mlx->mlx, st->mlx->win, st->img->img, 0, 0);
}

void	burningship(int xs, int ys, t_fac *st)
{
	st->var->row = 0;
	while (st->var->row < xs)
	{
		st->var->col = 0;
		while (st->var->col < ys)
		{
			st->var->x = ((st->var->col - xs / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->mx;
			st->var->y = ((st->var->row - ys / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->my;
			st->var->c_re = st->var->x;
			st->var->c_im = st->var->y;
			st->var->iteration = 0;
			drawship(st->var, st->img);
		st->var->col++;
		}
		st->var->row++;
	}
	mlx_put_image_to_window(st->mlx->mlx, st->mlx->win, st->img->img, 0, 0);
}

void	drawship(t_tv	*re, t_data *img)
{
	while (re->x * re->x + re->y * re->y <= 4 && re->iteration < re->max)
	{
		re->x_new = re->x * re->x - re->y * re->y + re->c_re;
		re->y = fabs(2 * re->x * re->y) + re->c_im;
		re->x = re->x_new;
		re->iteration++;
	}
	if (re->iteration == re->max)
		my_mlx_pixel_put(img, re->col, re->row, 0x00000000);
	else
		my_mlx_pixel_put(img, re->col, re->row, re->clr * re->iteration);
}

