/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_att.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:45:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 18:02:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_att_screen(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (SUCCESS);
}

void	ft_att_factor(t_data *data)
{
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
}

void	ft_att_z_value(t_data *data)
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

void	ft_att_pixel(t_data *data, int color)
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
