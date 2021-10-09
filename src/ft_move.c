/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/09 17:22:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_select(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("this is the key:	esc\n");
		ft_clear_memory(data);
	}
	else if (keycode == UP_ARROW)
	{
		printf("this is the key:	up\n");
		data->im.min += 0.1;
		data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		ft_calc_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == DOWN_ARROW)
	{
		printf("this is the key:	down\n");
		data->im.min -= 0.1;
		data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		ft_calc_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == LEFT_ARROW)
	{
		printf("this is the key:	left\n");
		data->real.min -= 0.1;
		data->real.max -= 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		ft_calc_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == RIGHT_ARROW)
	{
		printf("this is the key:	right\n");
		data->real.min += 0.1;
		data->real.max += 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		ft_calc_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == C_KEY)
		printf("this is the key:	c\n");
	return (1);
}