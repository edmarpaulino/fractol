/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/10 19:29:08 by edpaulin         ###   ########.fr       */
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
		data->im.max += 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == DOWN_ARROW)
	{
		printf("this is the key:	down\n");
		data->im.min -= 0.1;
		data->im.max -= 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == LEFT_ARROW)
	{
		printf("this is the key:	left\n");
		data->real.min -= 0.1;
		data->real.max -= 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == RIGHT_ARROW)
	{
		printf("this is the key:	right\n");
		data->real.min += 0.1;
		data->real.max += 0.1;
		data->img.y = -1;
		printf("data->im.min value:	%f\n", data->im.min);
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == C_KEY)
		printf("this is the key:	c\n");
	else if (keycode == SCROLL_UP)
	{
		printf("%f\n", 1.0);
		// printf("%f\n", data->real.max);
		// printf("%f\n", data->im.min);
		// printf("%f\n", data->im.max);
		// data->real.min += 0.005;
		// data->real.max -= 0.005;
		// data->im.min += 0.005;
		// data->im.max -= 0.005;
		// data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		// data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		// data->img.y = -1;
		// ft_calc_mandelbrot(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == SCROLL_DOWN)
	{
		printf("%f\n", 2.0);
		printf("%f\n", data->real.max);
		// printf("%f\n", data->im.min);
		// printf("%f\n", data->im.max);
		// data->real.min -= 0.005;
		// data->real.max += 0.005;
		// data->im.min -= 0.005;
		// data->im.max += 0.005;
		// data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		// data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		// data->img.y = -1;
		// ft_calc_mandelbrot(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (1);
}

int	ft_zoom(int keycode, t_data *data)
{
	if (keycode == SCROLL_UP)
	{
		printf("%f\n", data->real.min);
		// printf("%f\n", data->real.max);
		// printf("%f\n", data->im.min);
		// printf("%f\n", data->im.max);
		// data->real.min += 0.005;
		// data->real.max -= 0.005;
		// data->im.min += 0.005;
		// data->im.max -= 0.005;
		// data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		// data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		// data->img.y = -1;
		// ft_calc_mandelbrot(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == SCROLL_DOWN)
	{
		printf("%f\n", data->real.min);
		// printf("%f\n", data->real.max);
		// printf("%f\n", data->im.min);
		// printf("%f\n", data->im.max);
		// data->real.min -= 0.005;
		// data->real.max += 0.005;
		// data->im.min -= 0.005;
		// data->im.max += 0.005;
		// data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		// data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		// data->img.y = -1;
		// ft_calc_mandelbrot(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (1);
}
