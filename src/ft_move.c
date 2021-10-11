/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:03 by edpaulin         ###   ########.fr       */
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
		data->im.min += 0.01 * (data->im.max - data->im.min);
		data->im.max += 0.01 * (data->im.max - data->im.min);
		data->img.y = -1;
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
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
		data->im.min -= 0.01 * (data->im.max - data->im.min);
		data->im.max -= 0.01 * (data->im.max - data->im.min);
		data->img.y = -1;
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
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
		data->real.min -= 0.01 * (data->real.max - data->real.min);
		data->real.max -= 0.01 * (data->real.max - data->real.min);
		data->img.y = -1;
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
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
		data->real.min += 0.01 * (data->real.max - data->real.min);
		data->real.max += 0.01 * (data->real.max - data->real.min);
		data->img.y = -1;
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
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
	return (1);
}

int	ft_zoom(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_DOWN)
	{
		double	x_ratio = (double)x / data->width;
		double	y_ratio = (double)y / data->height;
		double	delta_re = data->real.max - data->real.min;
		double	delta_im = data->im.max - data->im.min;
		double	delta_delta_re = (1.05 * delta_re) - delta_re;
		double	delta_delta_im = (1.05 * delta_im) - delta_im;
		data->real.min -= (delta_delta_re * x_ratio);
		data->real.max += (delta_delta_re * (1.0 - x_ratio));
		data->im.max += (delta_delta_im * y_ratio);
		data->im.min -= (delta_delta_im * (1.0 - y_ratio));
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		printf("re.min:	%f|re.max:	%f|im.min:	%f|im.max:	%f\n", data->real.min, data->real.max, data->im.min, data->im.max);
		data->img.y = -1;
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == SCROLL_UP)
	{
		double	x_ratio = (double)x / data->width;
		double	y_ratio = (double)y / data->height;
		double	delta_re = data->real.max - data->real.min;
		double	delta_im = data->im.max - data->im.min;
		double	delta_delta_re = ((1.0 / 1.05) * delta_re) - delta_re;
		double	delta_delta_im = ((1.0 / 1.05) * delta_im) - delta_im;
		data->real.min -= (delta_delta_re * x_ratio);
		data->real.max += (delta_delta_re * (1.0 - x_ratio));
		data->im.max += (delta_delta_im * y_ratio);
		data->im.min -= (delta_delta_im * (1.0 - y_ratio));
		data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
		data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
		printf("re.min:	%f	|	re.max:	%f	|	im.min:	%f	|	im.max:	%f\n", \
				data->real.min, data->real.max, data->im.min, data->im.max);
		data->img.y = -1;
		if (data->epa == 1)
			ft_calc_mandelbrot(data);
		else if (data->epa == 2)
			ft_calc_julia(data);
		else if (data->epa == 3)
			ft_calc_burning_ship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (1);
}
