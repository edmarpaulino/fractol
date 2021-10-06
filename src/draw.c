/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:14:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/06 14:59:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 1 -> big endian
// 0 -> little endian

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

	pixel = (y * data->img.line_len) + (x * 4);
	if (data->img.endian == 1)
	{
		data->img.addr[pixel + 0] = (color >> 24);
		data->img.addr[pixel + 1] = (color >> 16) & 0xFF;
		data->img.addr[pixel + 2] = (color >> 8) & 0xFF;
		data->img.addr[pixel + 3] = (color) & 0xFF;
	}
	else if (data->img.endian == 0)
	{
		data->img.addr[pixel + 0] = (color) & 0xFF;
		data->img.addr[pixel + 1] = (color >> 8) & 0xFF;
		data->img.addr[pixel + 2] = (color >> 16) & 0xFF;
		data->img.addr[pixel + 3] = (color >> 24);
	}
}
