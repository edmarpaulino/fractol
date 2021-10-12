/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 12:12:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**str;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc < 2)
	{
		ft_options_message();
		return (1);
	}
	ft_strlower(argv[1]);
	data->color = 0;
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		ft_create_display(data);
		data->fractal = 0;
		ft_create_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
		mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
		mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
		mlx_mouse_hook(data->win, &ft_zoom, data);
		mlx_expose_hook(data->win, &ft_put_image_to_window, data);
		mlx_loop(data->mlx);
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 3)
	{
		if (ft_word_counter(argv[2]) == 2)
		{
			str = ft_split(argv[2], ' ');
			if (!ft_isalpha(ft_lastchr(str[0])) \
				&& ft_lastchr(str[1]) == 'i')
			{
				ft_create_display(data);
				data->cons.real = ft_atof(str[0]);
				data->cons.im = ft_atof(str[1]);
				data->fractal = 1;
				ft_create_fractal(data);
				mlx_put_image_to_window(data->mlx, data->win, \
										data->img.img, 0, 0);
				mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
				mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
				mlx_mouse_hook(data->win, &ft_zoom, data);
				mlx_expose_hook(data->win, &ft_put_image_to_window, data);
				mlx_loop(data->mlx);
			}
			if (ft_lastchr(str[0]) == 'i')
			{
				ft_options_message();
				mlx_destroy_image(data->mlx, data->img.img);
				mlx_destroy_window(data->mlx, data->win);
			}
			i = 0;
			while (str[i])
			{
				free(str[i]);
				i++;
			}
			free(str);
			ft_options_message();
			ft_clear_memory(data, EXIT_ERROR);
		}
		else
		{
			ft_options_message();
			mlx_destroy_image(data->mlx, data->img.img);
			mlx_destroy_window(data->mlx, data->win);
		}
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 4 \
			&& ft_lastchr(argv[2]) != 'i' \
			&& ft_lastchr(argv[3]) == 'i')
	{
		ft_create_display(data);
		data->cons.real = ft_atof(argv[2]);
		data->cons.im = ft_atof(argv[3]);
		data->fractal = 1;
		ft_create_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
		mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
		mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
		mlx_mouse_hook(data->win, &ft_zoom, data);
		mlx_expose_hook(data->win, &ft_put_image_to_window, data);
		mlx_loop(data->mlx);
	}
	else if (!ft_strcmp(argv[1], "burning") \
			|| !ft_strcmp(argv[1], "burning-ship"))
	{
		data->fractal = 2;
		ft_create_display(data);
		ft_create_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
		mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
		mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
		mlx_mouse_hook(data->win, &ft_zoom, data);
		mlx_expose_hook(data->win, &ft_put_image_to_window, data);
		mlx_loop(data->mlx);
	}
	else
	{
		ft_options_message();
		ft_clear_memory(data, EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}
