/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:37:14 by hmohamed          #+#    #+#             */
/*   Updated: 2023/02/06 17:09:48 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	def_var(t_fac *fc)
{
	fc->var->z = 1;
	fc->var->mx = 0;
	fc->var->my = 0;
	fc->var->max = 30;
	fc->var->clr = 0x00FF00AA;
}

void	manbord(int xs, int ys, t_fac *st)
{
	st->var->row = 0;
	while (st->var->row < xs)
	{
		st->var->col = 0;
		while (st->var->col < ys)
		{
			st->var->c_re = ((st->var->col - xs / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->mx;
			st->var->c_im = ((st->var->row - ys / 2.0) * 4.0 / xs)
				/ st->var->z + st->var->my;
			st->var->x = 0;
			st->var->y = 0;
			st->var->iteration = 0;
			drawmandel(st->var, st->img);
		st->var->col++;
		}
		st->var->row++;
	}
	mlx_put_image_to_window(st->mlx->mlx, st->mlx->win, st->img->img, 0, 0);
}

void	drawmandel(t_tv	*re, t_data *img)
{
	while (re->x * re->x + re->y * re->y <= 4 && re->iteration < re->max)
	{
		re->x_new = re->x * re->x - re->y * re->y + re->c_re;
		re->y = 2 * re->x * re->y + re->c_im;
		re->x = re->x_new;
		re->iteration++;
	}
	if (re->iteration == re->max)
		my_mlx_pixel_put(img, re->col, re->row, 0x00000000);
	else
		my_mlx_pixel_put(img, re->col, re->row, re->clr * re->iteration);
}
