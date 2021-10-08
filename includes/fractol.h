/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:46 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/08 22:54:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_calc
{
	double	min;
	double	max;
	double	factor;
	double	c;
	double	z;
	double	pow2;
}				t_calc;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	int		i;
	int		max_i;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*title;
	t_img	img;
	t_calc	real;
	t_calc	im;
}				t_data;

typedef struct s_const
{
	double	real;
	double	im;
}				t_const;

void			ft_att_pixel(t_data *data, int color);
void			ft_init_mandelbrot(t_data *data);
void			ft_calc_mandelbrot(t_data *data);
void			ft_init_julia(t_data *data, t_const *c);
void			ft_calc_julia(t_data *data, t_const *c);
void			ft_init_burning_ship(t_data *data);
void			ft_calc_burning_ship(t_data *data);
void			ft_burning_ship(t_data *data);
unsigned int	ft_get_color(int n);

#endif
