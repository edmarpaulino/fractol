/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:10:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 12:21:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom_calc(t_data *data, int x, int y, char direction)
{
	t_zoom	zoom;

	zoom.x_ratio = (double)x / data->width;
	zoom.y_ratio = (double)y / data->height;
	zoom.delta_re = data->real.max - data->real.min;
	zoom.delta_im = data->im.max - data->im.min;
	zoom.delta_delta_re = 0;
	zoom.delta_delta_im = 0;
	if (direction == ZOOM_IN)
	{
		zoom.delta_delta_re = ((1.0 / 1.05) * zoom.delta_re) - zoom.delta_re;
		zoom.delta_delta_im = ((1.0 / 1.05) * zoom.delta_im) - zoom.delta_im;
	}
	else if (direction == ZOOM_OUT)
	{
		zoom.delta_delta_re = (1.05 * zoom.delta_re) - zoom.delta_re;
		zoom.delta_delta_im = (1.05 * zoom.delta_im) - zoom.delta_im;
	}
	data->real.min -= (zoom.delta_delta_re * zoom.x_ratio);
	data->real.max += (zoom.delta_delta_re * (1.0 - zoom.x_ratio));
	data->im.max += (zoom.delta_delta_im * zoom.y_ratio);
	data->im.min -= (zoom.delta_delta_im * (1.0 - zoom.y_ratio));
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
}

int	ft_zoom(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_DOWN)
	{
		ft_zoom_calc(data, x, y, ZOOM_OUT);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == SCROLL_UP)
	{
		ft_zoom_calc(data, x, y, ZOOM_IN);
		ft_draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (SUCCESS);
}
