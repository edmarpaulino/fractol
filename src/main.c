/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/06 14:29:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_data data;
	
	data.mlx = mlx_init();
	data.height = 600;
	data.width = 800;
	data.title = "fractol";
	data.win = mlx_new_window(data.mlx, data.width, data.height, data.title);
	data.img.img = mlx_new_image(data.mlx, data.width, data.height);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
									  &data.img.line_len, &data.img.endian);
	ft_mandelbrot(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
}
