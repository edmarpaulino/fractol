/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 10:59:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key(int keycode)
{
	printf("this is the key:	%d\n", keycode);
	return (1);
}

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
	if (ft_init_display(data) == -1)
		ft_clear_memory(data);
	ft_strlower(argv[1]);
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		data->epa = 1;
		ft_init_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
		mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
		mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
		mlx_mouse_hook(data->win, &ft_zoom, data);
		// mlx_mouse_hook(data->win, &ft_key, data);
		mlx_expose_hook(data->win, &ft_put_image_to_window, data);
		mlx_loop(data->mlx);
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 3 \
			&& ft_lastchr(argv[2]) == 'i') // fix this
	{
		if (ft_word_counter(argv[2]) == 2)
		{
			str = ft_split(argv[2], ' ');
			if (!ft_isalpha(ft_lastchr(str[0])))
			{
				data->c.real = ft_atof(str[0]);
				data->c.im = ft_atof(str[1]);
				data->epa = 2;
				ft_init_julia(data);
				mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
				mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
				mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
				mlx_mouse_hook(data->win, &ft_zoom, data);
				mlx_expose_hook(data->win, &ft_put_image_to_window, data);
				mlx_loop(data->mlx);
				i = 0;
			}
			if (ft_lastchr(str[0]) == 'i')
			{
				ft_options_message();
				mlx_destroy_image(data->mlx, data->img.img);
				mlx_destroy_window(data->mlx, data->win);
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
			mlx_destroy_image(data->mlx, data->img.img);
			mlx_destroy_window(data->mlx, data->win);
		}
	}
	else if (!ft_strcmp(argv[1], "julia") \
			&& argc == 4 \
			&& ft_lastchr(argv[2]) != 'i' \
			&& ft_lastchr(argv[3]) == 'i')
	{
		data->c.real = ft_atof(argv[2]);
		data->c.im = ft_atof(argv[3]);
		data->epa = 2;
		ft_init_julia(data);
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
		data->epa = 3;
		ft_init_burning_ship(data);
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
		ft_clear_memory(data);
	}
	return (0);
}
