/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:14:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 12:21:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 1 -> big endian
// 0 -> little endian

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

unsigned int	ft_get_color(int n)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;

	t = pow(log(((double)(n % 128))) / log(128.0), 2);
	color = 0x101010;
	if (t < 0.99)
	{
		r = 8 * (1 - t) * t * t * t * 255;
		g = 14 * (1 - t) * (1 - t) * t * t * 255;
		b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
		color = r << 16 | g << 8 | b;
	}
	return (color);
}

int	ft_put_image_to_window(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (1);
}
