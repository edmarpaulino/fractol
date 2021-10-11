/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:05:02 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 10:55:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init_display(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->height = 600;
	data->width = 800;
	data->title = "fractol";
	data->win = mlx_new_window(data->mlx, data->width, \
								data->height, data->title);
	if (!data->win)
		return (-1);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img.img)
		return (-1);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
										&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (-1);
	return (1);
}

void	ft_init_mandelbrot(t_data *data)
{
	data->real.min = -2.0;
	data->real.max = 2.0;
	data->im.min = -1.2;
	data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
	data->img.max_i = 27;
	data->img.y = -1;
	data->img.x = -1;
	ft_calc_mandelbrot(data);
}


void	ft_init_julia(t_data *data)
{
	data->real.min = -2.5;
	data->real.max = data->real.min + 3.5;
	data->im.min = -1.2;
	data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
	data->img.max_i = 27;
	data->img.y = -1;
	data->img.x = -1;
	ft_calc_julia(data);
}

void	ft_init_burning_ship(t_data *data)
{
	data->real.min = -2.5;
	data->real.max = data->real.min + 3.5;
	data->im.min = -1.2;
	data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
	data->im.min = -data->im.min;
	data->im.max = -data->im.max;
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
	data->img.max_i = 27;
	data->img.y = -1;
	data->img.x = -1;
	ft_calc_burning_ship(data);
}
