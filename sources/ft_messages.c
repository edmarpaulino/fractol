/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:10:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 18:02:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_options_message(void)
{
	printf("\nFractals (no case sensitive):\n");
	printf("\t-Mandelbrot\n\t-Julia\n\t-Burning Ship\n");
	printf("\vRun exemple:\n");
	printf("./fractol mandelbrot\n");
	printf("./fractol julia (need more arguments - more examples below)\n");
	printf("./fractol burning-ship\n");
	printf("\vCall Julia fractal like this:\n");
	printf("./fractol julia \"-0.428 -0.580i\"\n");
	printf("./fractol julia -0.428 -0.580i\n");
}

void	ft_error_message(int error_type)
{
	if (error_type == FEW_ARGS)
		ft_putendl_fd("== ERROR == Few arguments.", 2);
	else if (error_type == INVALID_ARGS)
		ft_putendl_fd("== ERROR == Invalid arguments.", 2);
	ft_options_message();
}
