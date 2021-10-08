/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/08 22:34:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_const	c;

	if (argc < 2)
		return (1);
	data.mlx = mlx_init();
	data.height = 600;
	data.width = 800;
	data.title = "fractol";
	data.win = mlx_new_window(data.mlx, data.width, data.height, data.title);
	data.img.img = mlx_new_image(data.mlx, data.width, data.height);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, \
										&data.img.line_len, &data.img.endian);
	ft_strlower(argv[1]);
	if (!ft_strcmp(argv[1], "mandelbrot"))
		ft_init_mandelbrot(&data);
	else if (!ft_strcmp(argv[1], "julia") && argc == 4)
	{
		printf("argv[2]:	%s\nargv[3]:	%s\n", argv[2], argv[3]);
		c.real = ft_atof(argv[2]);
		c.im = ft_atof(argv[3]);
		printf("c.real:	%f\nc.im:	%f\n", c.real, c.im);
		ft_init_julia(&data, &c);
	}
	else if (!ft_strcmp(argv[1], "burning"))
		ft_init_burning_ship(&data);
	else
	{
		mlx_destroy_image(data.mlx, data.img.img);
		mlx_destroy_window(data.mlx, data.win);
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
}
