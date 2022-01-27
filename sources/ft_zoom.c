/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:10:26 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/27 19:05:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_zoom_values(t_data *data, t_zoom *zoom, int x, int y)
{
	zoom->x_ratio = (double)x / data->width;
	zoom->y_ratio = (double)y / data->height;
	zoom->delta_re = data->real.max - data->real.min;
	zoom->delta_im = data->im.max - data->im.min;
	zoom->delta_delta_re = 0;
	zoom->delta_delta_im = 0;
}

static void	ft_define_zoom_direction(t_zoom *zoom, char direction)
{
	if (direction == ZOOM_IN)
	{
		zoom->delta_delta_re = ((1.0 / 1.05) * zoom->delta_re) - zoom->delta_re;
		zoom->delta_delta_im = ((1.0 / 1.05) * zoom->delta_im) - zoom->delta_im;
	}
	else if (direction == ZOOM_OUT)
	{
		zoom->delta_delta_re = (1.05 * zoom->delta_re) - zoom->delta_re;
		zoom->delta_delta_im = (1.05 * zoom->delta_im) - zoom->delta_im;
	}
}

static void	ft_calc_zoom(t_data *data, t_zoom *zoom)
{
	data->real.min -= (zoom->delta_delta_re * zoom->x_ratio);
	data->real.max += (zoom->delta_delta_re * (1.0 - zoom->x_ratio));
	data->im.max += (zoom->delta_delta_im * zoom->y_ratio);
	data->im.min -= (zoom->delta_delta_im * (1.0 - zoom->y_ratio));
}

static void	ft_apply_zoom(t_data *data, int x, int y, char direction)
{	
	t_zoom	zoom;

	ft_init_zoom_values(data, &zoom, x, y);
	ft_define_zoom_direction(&zoom, direction);
	ft_calc_zoom(data, &zoom);
	ft_att_factor(data);
	ft_draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	ft_zoom(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_DOWN)
		ft_apply_zoom(data, x, y, ZOOM_OUT);
	else if (keycode == SCROLL_UP)
		ft_apply_zoom(data, x, y, ZOOM_IN);
	return (SUCCESS);
}
