/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:23:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 10:05:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_individual_param(const char *s)
{
	char	signal;
	char	dot;

	signal = 0;
	dot = 0;
	while (*s && *s != 'i')
	{
		if (*s == '-' || *s == '+')
			signal++;
		else if (*s == '.')
		{
			if (!ft_isdigit(*(s + 1)))
				return (FALSE);
			dot++;
		}
		else if (!ft_isdigit(*s))
			return (FALSE);
		if (signal > 1 || dot > 1)
			return (FALSE);
		++s;
	}
	return (TRUE);
}

static int	ft_check_params(const char *p1, const char *p2)
{
	if (ft_lastchr(p1) == 'i' || ft_lastchr(p2) != 'i')
		return (FALSE);
	return (ft_check_individual_param(p1) && ft_check_individual_param(p2));
}

static void	ft_get_coordenates(char **argv, t_data *data)
{
	data->cons.coor = ft_split(argv[2], ' ');
	if (ft_check_params(data->cons.coor[0], data->cons.coor[1]))
	{
		data->cons.real = ft_atof(data->cons.coor[0]);
		data->cons.im = ft_atof(data->cons.coor[1]);
	}
	else
	{
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
			&& ft_check_params(argv[2], argv[3]))
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
