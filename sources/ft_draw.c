/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:14:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 11:05:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 1 -> big endian
// 0 -> little endian

void	ft_att_pixel(t_data *data)
{
	int	pixel;

	pixel = (data->img.y * data->img.line_len) + \
			(data->img.x * 4);
	if (data->img.endian == 1)
	{
		data->img.addr[pixel + 0] = (data->img.pixel_color >> 24);
		data->img.addr[pixel + 1] = (data->img.pixel_color >> 16) & 0xFF;
		data->img.addr[pixel + 2] = (data->img.pixel_color>> 8) & 0xFF;
		data->img.addr[pixel + 3] = (data->img.pixel_color) & 0xFF;
	}
	else if (data->img.endian == 0)
	{
		data->img.addr[pixel + 0] = (data->img.pixel_color) & 0xFF;
		data->img.addr[pixel + 1] = (data->img.pixel_color >> 8) & 0xFF;
		data->img.addr[pixel + 2] = (data->img.pixel_color>> 16) & 0xFF;
		data->img.addr[pixel + 3] = (data->img.pixel_color>> 24);
	}
}

void	ft_get_color(t_data *data)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = pow(log(((double)(data->img.i % 128))) / log(128.0), 2);
	data->img.pixel_color = 0x101010;
	if (t < 0.99)
	{
		r = 8 * (1 - t) * t * t * t * 255;
		g = 14 * (1 - t) * (1 - t) * t * t * 255;
		b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
		if (data->color == 0)
			data->img.pixel_color = r << 16 | g << 8 | b;
		else if (data->color == 1)
			data->img.pixel_color = r << 16 | b << 8 | g;
		else if (data->color == 2)
			data->img.pixel_color = g << 16 | b << 8 | r;
		else if (data->color == 3)
			data->img.pixel_color = g << 16 | r << 8 | b;
		else if (data->color == 4)
			data->img.pixel_color = b << 16 | r << 8 | g;
		else if (data->color == 5)
			data->img.pixel_color = b << 16 | g << 8 | r;
	}
	ft_att_pixel(data);
}

int	ft_put_image_to_window(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (1);
}

static void	ft_att_z_value(t_data *data)
{
	if (data->fractal == MANDELBROT)
	{
		data->im.z = 2 * data->real.z * data->im.z + data->im.c;
		data->real.z = data->real.z_pow2 - data->im.z_pow2 + data->real.c;
	}
	else if (data->fractal == JULIA)
	{
		data->im.z = 2 * data->real.z * data->im.z + data->cons.im;
		data->real.z = data->real.z_pow2 - data->im.z_pow2 + data->cons.real;
	}
	else if (data->fractal == BURNING_SHIP)
	{
		data->im.z = fabs(2 * data->real.z * data->im.z) + data->im.c;
		data->real.z = data->real.z_pow2 - data->im.z_pow2 + data->real.c;
	}
}

void	ft_draw_fractal(t_data *data)
{
	data->img.y = -1;
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
				data->real.z_pow2 = data->real.z * data->real.z;
				data->im.z_pow2 = data->im.z * data->im.z;
				if (data->real.z_pow2 + data->im.z_pow2 > 4)
					break ;
				data->img.pixel_color = 0x00000000;
				ft_att_pixel(data);
				ft_att_z_value(data);
			}
			ft_get_color(data);
		}
	}
}
