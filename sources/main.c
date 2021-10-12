/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 18:17:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
	{
		ft_error_message(FEW_ARGS);
		return (EXIT_FAILURE);
	}
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (EXIT_FAILURE);
		ft_init_pointers(data);
		ft_init(argc, argv, data);
	}
	mlx_hook(data->win, 17, 1L << 0, &ft_clear_memory, data);
	mlx_hook(data->win, 2, 1L << 0, &ft_key_select, data);
	mlx_mouse_hook(data->win, &ft_zoom, data);
	mlx_expose_hook(data->win, &ft_att_screen, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
