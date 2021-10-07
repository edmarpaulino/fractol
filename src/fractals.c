/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:26:31 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/07 15:26:51 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_data *data)
{
	double	max_iterations;
	double	y;
	double	x;
	double	n;
	int		color;

	data->real.min = -1.5;
	data->real.max = data->real.min + 2.5;
	data->im.min = -1.2;
	data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
	data->real.factor= (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
	max_iterations = 600;
	y = 0;
	while ((signed int)y < data->height)
	{
		data->im.c = data->im.max - y * data->im.factor;
		x = 0;
		while ((signed int)x < data->width)
		{
			data->real.c = data->real.min + x * data->real.factor;
			data->real.z = data->real.c;
			data->im.z = data->im.c;
			n = 0;
			while (n < max_iterations)
			{
				data->real.pow2 = data->real.z * data->real.z;
				data->im.pow2 = data->im.z * data->im.z;
				if (data->real.pow2 + data->im.pow2 > 4)
				{
					color = (0x00111111 + (int)n * 8) << 16;
					ft_put_pixel(data, x, y, color);
					break;
				}
				data->im.z = fabs(2 * data->real.z * data->im.z) + data->im.c;
				data->real.z = data->real.pow2 - data->im.pow2 + data->real.c;
				n++;
			}
			x++;
		}
		y++;
	}
}
