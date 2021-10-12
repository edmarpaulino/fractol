/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:23:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 18:20:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_get_coordenates(char **argv, t_data *data)
{
	data->cons.coor = ft_split(argv[2], ' ');
	if (!ft_isalpha(ft_lastchr(data->cons.coor[0])) && \
		ft_lastchr(data->cons.coor[1]) == 'i')
	{
		data->cons.real = ft_atof(data->cons.coor[0]);
		data->cons.im = ft_atof(data->cons.coor[1]);
	}
	else
	{
		ft_clear_split(data->cons.coor);
		ft_error_message(INVALID_ARGS);
		ft_clear_memory(data, EXIT_FAILURE);
	}	
}

void	ft_init(int argc, char **argv, t_data *data)
{
	ft_strlower(argv[1]);
	data->color = 0;
	if (!ft_strcmp(argv[1], "mandelbrot"))
		data->fractal = 0;
	else if (!ft_strcmp(argv[1], "julia") && argc == 3)
	{
		data->fractal = 1;
		ft_get_coordenates(argv, data);
	}
	else if (!ft_strcmp(argv[1], "julia") && argc > 3 \
			&& ft_lastchr(argv[2]) != 'i' && ft_lastchr(argv[3]) == 'i')
	{
		data->fractal = 1;
		data->cons.real = ft_atof(argv[2]);
		data->cons.im = ft_atof(argv[3]);
	}
	else if (!ft_strcmp(argv[1], "burning-ship"))
		data->fractal = 2;
	else
	{
		ft_error_message(INVALID_ARGS);
		ft_clear_memory(data, EXIT_FAILURE);
	}	
	ft_create_display(data);
	ft_create_fractal(data);
}

void	ft_init_pointers(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->cons.coor = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
}
