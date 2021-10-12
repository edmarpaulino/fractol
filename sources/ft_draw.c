/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:14:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 16:10:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 1 -> big endian
// 0 -> little endian

int	ft_redraw(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (SUCCESS);
}

static void	ft_att_pixel(t_data *data, int color)
{
	int	pixel;

	pixel = (data->img.y * data->img.line_len) + \
			(data->img.x * 4);
	if (data->img.endian == 1)
	{
		data->img.addr[pixel + 0] = (color >> 24);
		data->img.addr[pixel + 1] = (color >> 16) & 0xFF;
		data->img.addr[pixel + 2] = (color >> 8) & 0xFF;
		data->img.addr[pixel + 3] = (color) & 0xFF;
	}
	else if (data->img.endian == 0)
	{
		data->img.addr[pixel + 0] = (color) & 0xFF;
		data->img.addr[pixel + 1] = (color >> 8) & 0xFF;
		data->img.addr[pixel + 2] = (color >> 16) & 0xFF;
		data->img.addr[pixel + 3] = (color >> 24);
	}
}

static void	ft_get_color(t_data *data)
{
	t_color	color;

	color.t = pow(log(((double)(data->img.i % 128))) / log(128.0), 2);
	if (color.t < 0.99)
	{
		color.r = 8 * (1 - color.t) * pow(color.t, 3) * 255;
		color.g = 14 * pow((1 - color.t), 2) * pow(color.t, 2) * 255;
		color.b = 8.5 * pow((1 - color.t), 3) * color.t * 255;
		if (data->color == 0)
			ft_att_pixel(data, (color.r << 16 | color.g << 8 | color.b));
		else if (data->color == 1)
			ft_att_pixel(data, (color.r << 16 | color.b << 8 | color.g));
		else if (data->color == 2)
			ft_att_pixel(data, (color.g << 16 | color.b << 8 | color.r));
		else if (data->color == 3)
			ft_att_pixel(data, (color.g << 16 | color.r << 8 | color.b));
		else if (data->color == 4)
			ft_att_pixel(data, (color.b << 16 | color.r << 8 | color.g));
		else if (data->color == 5)
			ft_att_pixel(data, (color.b << 16 | color.g << 8 | color.r));
	}
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
				data->real.z_pow2 = pow(data->real.z, 2);
				data->im.z_pow2 = pow(data->im.z, 2);
				if (data->real.z_pow2 + data->im.z_pow2 > 4)
				{
					ft_get_color(data);
					break ;
				}
				ft_att_pixel(data, 0x00000000);
				ft_att_z_value(data);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
