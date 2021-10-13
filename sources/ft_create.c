/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:05:02 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 14:37:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_create_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->width, \
								data->height, data->title);
	if (!data->win)
		ft_clear_memory(data, EXIT_FAILURE);
}

static void	ft_create_image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img.img)
		ft_clear_memory(data, EXIT_FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
										&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		ft_clear_memory(data, EXIT_FAILURE);
}

static void	ft_create_limits(t_data *data, double x_min, \
								double x_max, double y_min)
{
	data->real.min = x_min;
	data->real.max = x_max;
	data->im.min = y_min;
	data->im.max = data->im.min + \
				(data->real.max - data->real.min) * \
				data->height / data->width;
	if (data->fractal == BURNING_SHIP)
	{
		data->im.min = -data->im.min;
		data->im.max = -data->im.max;
	}
	data->img.max_i = MAX_I;
}

void	ft_create_display(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_clear_memory(data, EXIT_FAILURE);
	data->height = 600;
	data->width = 800;
	data->title = "fractol";
	ft_create_window(data);
	ft_create_image(data);
}

void	ft_create_fractal(t_data *data)
{
	if (data->fractal == MANDELBROT)
		ft_create_limits(data, -2.5, 1.5, -1.5);
	else if (data->fractal == JULIA)
		ft_create_limits(data, -2.0, 2.0, -1.5);
	else
		ft_create_limits(data, -2.5, 2.0, -1.4);
	ft_att_factor(data);
	ft_draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
