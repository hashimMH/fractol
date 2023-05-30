/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:02:12 by hmohamed          #+#    #+#             */
/*   Updated: 2023/02/21 14:27:10 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_fac	f;
	t_data	img;
	t_mlx	mlx;
	t_tv	tv;

	tv.id = parc_fractol(av, ac, &tv);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1080, 1080, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.img = &img;
	f.mlx = &mlx;
	f.var = &tv;
	def_var(&f);
	drawone(&f);
	mlx_hook(f.mlx->win, 2, 0, key, &f);
	mlx_mouse_hook(f.mlx->win, mousekey, &f);
	mlx_hook(f.mlx->win, 17, 0, destroy, &f);
	mlx_loop(f.mlx->mlx);
}
