/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:26:31 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/06 17:55:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_data *data)
{
	double	min_real;
	double	max_real;
	double	min_im;
	double	max_im;
	double	real_factor;
	double	im_factor;
	double	max_iterations;
	double	y;
	double	x;
	double	n;
	double	c_im;
	double	c_real;
	double	z_real;
	double	z_real2;
	double	z_im;
	double	z_im2;
	char	is_inside;
	int		color;

	min_real = -1.5;
	max_real = min_real + 2.5;
	min_im = -1.2;
	max_im = min_im + (max_real - min_real) * data->height / data->width;
	real_factor = (max_real - min_real) / (data->width - 1);
	im_factor = (max_im - min_im) / (data->height - 1);
	max_iterations = 600;
	y = 0;
	while ((signed int)y < data->height)
	{
		c_im = max_im - y * im_factor;
		x = 0;
		while ((signed int)x < data->width)
		{
			c_real = min_real + x * real_factor;
			z_real = c_real;
			z_im = c_im;
			is_inside = 1;
			n = 0;
			while (n < max_iterations)
			{
				z_real2 = z_real * z_real;
				z_im2 = z_im * z_im;
				if (z_real2 + z_im2 > 4)
				{
					is_inside = 0;
					break;
				}
				z_im = fabs(2 * z_real * z_im) + c_im;
				z_real = z_real2 - z_im2 + c_real;
				n++;
			}
			if (!is_inside)
			{
				color = (0x00111111 + (int)n * 8) << 16;
				ft_put_pixel(data, x, y, color);
			}
			x++;
		}
		y++;
	}
}
