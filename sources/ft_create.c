/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:05:02 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 15:21:27 by edpaulin         ###   ########.fr       */
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

void	ft_att_factor(t_data *data)
{
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
}

void	ft_create_fractal(t_data *data)
{
	data->real.min = -2.0;
	data->real.max = 2.0;
	data->im.min = -1.2;
	data->im.max = 1.8;
	if (data->fractal == BURNING_SHIP)
	{
		data->im.min = -data->im.min;
		data->im.max = -data->im.max;
	}
	ft_att_factor(data);
	data->img.max_i = MAX_I;
	ft_draw_fractal(data);
}
