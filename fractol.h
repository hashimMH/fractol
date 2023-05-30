/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:49:49 by hmohamed          #+#    #+#             */
/*   Updated: 2023/02/06 16:54:42 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct dv
{
	double			c_re;
	double			c_im;
	int				max;
	int				row;
	int				col;
	unsigned int	clr;
	double			x;
	double			y;
	int				iteration;
	double			x_new;
	double			z;
	double			mx;
	double			my;
	double			jnx;
	double			jny;
	int				id;
}				t_tv;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_fac
{
	struct s_mlx	*mlx;
	struct s_data	*img;
	struct dv		*var;
}	t_fac;

void	drawmandel(t_tv	*re, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	manbord(int xs, int ys, t_fac *st);
void	def_var(t_fac *fc);
void	julia(int xs, int ys, t_fac *st);
int		parc_fractol(char **str, int an, t_tv *tv);
void	drawone(t_fac *st);
int		key(int keycode, t_fac *st);
int		mousekey(int keycode, int x, int y, t_fac *st);
int		destroy(t_fac *f);
void	hook(int keycode, t_fac *st);
void	color(int keycode, t_fac *st);
void	burningship(int xs, int ys, t_fac *st);
void	drawship(t_tv	*re, t_data *img);

#endif