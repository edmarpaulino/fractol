/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:10:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/12 15:34:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_options_message(void)
{
	printf("Fractals (no case sensitive):\n");
	printf("\t-Mandelbrot\n\t-Julia\n\t-Burning Ship\n");
	printf("\vRun exemple:\n");
	printf("./fractol mandelbrot\n");
	printf("./fractol julia (need more arguments - more examples below)\n");
	printf("./fractol burning-ship\n");
	printf("\vCall Julia fractal like this:\n");
	printf("./fractol julia \"-0.428 -0.580i\"\n");
	printf("./fractol julia -0.428 -0.580i\n");
}
