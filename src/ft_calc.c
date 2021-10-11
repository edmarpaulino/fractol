/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:20:48 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 17:52:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_mandelbrot(t_data *data)
{
	while (++data->img.y < data->height)
	{
		data->im.c = data->im.max - data->img.y * data->im.factor;
		data->img.x = -1;
		while (++data->img.x < data->width)
		{
			data->real.c = data->real.min + data->img.x * data->real.factor;
			data->real.z = data->real.c;
			data->im.z = data->im.c;
			data->img.i = -1;
			while (++data->img.i < data->img.max_i)
			{
				data->real.pow2 = data->real.z * data->real.z;
				data->im.pow2 = data->im.z * data->im.z;
				if (data->real.pow2 + data->im.pow2 > 4)
				{
					ft_att_pixel(data,\
								ft_get_color(data->img.i, data->ch_color));
					break ;
				}
				else
					ft_att_pixel(data, 0x00000000);
				data->im.z = 2 * data->real.z * data->im.z + data->im.c;
				data->real.z = data->real.pow2 - data->im.pow2 + data->real.c;
			}
		}
	}
}

void	ft_calc_julia(t_data *data)
{
	while (++data->img.y < data->height)
	{
		data->im.c = data->im.max - data->img.y * data->im.factor;
		data->img.x = -1;
		while (++data->img.x < data->width)
		{
			data->real.c = data->real.min + data->img.x * data->real.factor;
			data->real.z = data->real.c;
			data->im.z = data->im.c;
			data->img.i = -1;
			while (++data->img.i < data->img.max_i)
			{
				data->real.pow2 = data->real.z * data->real.z;
				data->im.pow2 = data->im.z * data->im.z;
				if (data->real.pow2 + data->im.pow2 > 4)
				{
					ft_att_pixel(data,\
								ft_get_color(data->img.i, data->ch_color));
					break ;
				}
				else
					ft_att_pixel(data, 0x00000000);
				data->im.z = 2 * data->real.z * data->im.z + data->c.im;
				data->real.z = data->real.pow2 - data->im.pow2 + data->c.real;
			}
		}
	}
}

void	ft_calc_burning_ship(t_data *data)
{
	while (++data->img.y < data->height)
	{
		data->im.c = data->im.max - data->img.y * data->im.factor;
		data->img.x = -1;
		while (++data->img.x < data->width)
		{
			data->real.c = data->real.min + data->img.x * data->real.factor;
			data->real.z = data->real.c;
			data->im.z = data->im.c;
			data->img.i = -1;
			while (++data->img.i < data->img.max_i)
			{
				data->real.pow2 = data->real.z * data->real.z;
				data->im.pow2 = data->im.z * data->im.z;
				if (data->real.pow2 + data->im.pow2 > 4)
				{
					ft_att_pixel(data,\
								ft_get_color(data->img.i, data->ch_color));
					break ;
				}
				else
					ft_att_pixel(data, 0x00000000);
				data->im.z = fabs(2 * data->real.z * data->im.z) + data->im.c;
				data->real.z = data->real.pow2 - data->im.pow2 + data->real.c;
			}
		}
	}
}
