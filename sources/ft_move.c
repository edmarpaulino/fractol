/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 11:26:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_select(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_clear_memory(data, EXIT_SUCCESS);
	else if (keycode == UP_ARROW)
	{
		data->im.min += 0.01 * (data->im.max - data->im.min);
		data->im.max += 0.01 * (data->im.max - data->im.min);
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == DOWN_ARROW)
	{
		data->im.min -= 0.01 * (data->im.max - data->im.min);
		data->im.max -= 0.01 * (data->im.max - data->im.min);
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == LEFT_ARROW)
	{
		data->real.min -= 0.01 * (data->real.max - data->real.min);
		data->real.max -= 0.01 * (data->real.max - data->real.min);
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == RIGHT_ARROW)
	{
		data->real.min += 0.01 * (data->real.max - data->real.min);
		data->real.max += 0.01 * (data->real.max - data->real.min);
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == C_KEY)
	{
		data->color = (data->color + 1) % 6;
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (1);
}
