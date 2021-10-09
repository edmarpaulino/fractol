/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/09 12:55:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_const	c;
	char	**str;
	int		i;

	if (argc < 2)
	{
		ft_options_message();
		return (1);
	}
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
	{
		ft_init_mandelbrot(&data);
		mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 3 \
			&& ft_lastchr(argv[2]) == 'i') // fix this
	{
		if (ft_word_counter(argv[2]) == 2)
		{
			str = ft_split(argv[2], ' ');
			if (ft_lastchr(str[0]) != 'i')
			{
				c.real = ft_atof(str[0]);
				c.im = ft_atof(str[1]);
				ft_init_julia(&data, &c);
				mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
				mlx_loop(data.mlx);
				i = 0;
			}
			if (ft_lastchr(str[0]) == 'i')
			{
				ft_options_message();
				mlx_destroy_image(data.mlx, data.img.img);
				mlx_destroy_window(data.mlx, data.win);
			}
			while (str[i])
			{
				free(str[i]);
				i++;
			}
			free(str);
		}
		else
		{
			ft_options_message();
			mlx_destroy_image(data.mlx, data.img.img);
			mlx_destroy_window(data.mlx, data.win);
		}
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 4 \
			&& ft_lastchr(argv[2]) != 'i' \
			&& ft_lastchr(argv[3]) == 'i')
	{
		c.real = ft_atof(argv[2]);
		c.im = ft_atof(argv[3]);
		ft_init_julia(&data, &c);
		mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else if (!ft_strcmp(argv[1], "burning"))
	{
		ft_init_burning_ship(&data);
		mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_options_message();
		mlx_destroy_image(data.mlx, data.img.img);
		mlx_destroy_window(data.mlx, data.win);
	}
	return (0);
}
