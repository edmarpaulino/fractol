/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:23:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_get_coordenates(char **argv, t_data *data)
{
	char	**coor;

	coor = ft_split(argv[2], ' ');
	if (!ft_isalpha(ft_lastchr(coor[0])) && ft_lastchr(coor[1]) == 'i')
	{
		data->cons.real = ft_atof(coor[0]);
		data->cons.im = ft_atof(coor[1]);
	}
	else
	{
		ft_clear_split(coor);
		ft_options_message();
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
		ft_options_message();
		ft_clear_memory(data, EXIT_FAILURE);
	}	
	ft_create_display(data);
	ft_create_fractal(data);
}
