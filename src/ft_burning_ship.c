/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:44:11 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/08 16:53:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_burning_ship(t_data *data)
{
	data->real.min = -1.5;
	data->real.max = data->real.min + 2.5;
	data->im.min = -1.2;
	data->im.max = data->im.min + \
					(data->real.max - data->real.min) * \
					data->height / data->width;
	data->im.min = -data->im.min;
	data->im.max = -data->im.max;
	data->real.factor = (data->real.max - data->real.min) / (data->width - 1);
	data->im.factor = (data->im.max - data->im.min) / (data->height - 1);
	data->img.max_i = 600;
	data->img.y = -1;
	data->img.x = -1;
	ft_calc_burning_ship(data);
}

void	ft_calc_burning_ship(t_data *data)
{
	while (++data->img.y < data->height)
	{
		data->im.c = data->im.max - data->img.y * data->im.factor;
		data->img.x = -1;
		while (++data->img.x < data->width)
		{
			data->real.c = data->real.min + data->img.x * data->real.factor;
			data->real.z = data->real.c;
			data->im.z = data->im.c;
			data->img.i = -1;
			while (++data->img.i < data->img.max_i)
			{
				data->real.pow2 = data->real.z * data->real.z;
				data->im.pow2 = data->im.z * data->im.z;
				if (data->real.pow2 + data->im.pow2 > 6)
				{
					ft_att_pixel(data, ft_get_color(data->img.i));
					break ;
				}
				data->im.z = fabs(2 * data->real.z * data->im.z) + data->im.c;
				data->real.z = data->real.pow2 - data->im.pow2 + data->real.c;
			}
		}
	}
}
