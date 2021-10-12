/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 15:45:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_negative_move(double *min, double *max, t_data *data)
{
	*min -= 0.01 * (*max - *min);
	*max -= 0.01 * (*max - *min);
	ft_att_factor(data);
	ft_draw_fractal(data);
}

static void	ft_positive_move(double *min, double *max, t_data *data)
{
	*min += 0.01 * (*max - *min);
	*max += 0.01 * (*max - *min);
	ft_att_factor(data);
	ft_draw_fractal(data);
}

int	ft_key_select(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_clear_memory(data, EXIT_SUCCESS);
	else if (keycode == UP_ARROW)
		ft_positive_move(&data->im.min, &data->im.max, data);
	else if (keycode == DOWN_ARROW)
		ft_negative_move(&data->im.min, &data->im.max, data);
	else if (keycode == LEFT_ARROW)
		ft_negative_move(&data->real.min, &data->real.max, data);
	else if (keycode == RIGHT_ARROW)
		ft_positive_move(&data->real.min, &data->real.max, data);
	else if (keycode == C_KEY)
	{
		data->color = (data->color + 1) % 6;
		ft_draw_fractal(data);
	}
	return (SUCCESS);
}
