/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:46 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/06 14:27:40 by edpaulin         ###   ########.fr       */
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

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_color	color;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*title;
	t_img	img;
}				t_data;

void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_mandelbrot(t_data *data);

#endif
