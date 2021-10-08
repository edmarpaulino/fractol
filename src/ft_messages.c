/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:10:53 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/09 01:26:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_options_message(void)
{
	printf("Fractals (no case sensitive):\n\t-Mandelbrot\n\t-Julia\n\t-Burning Ship\n");
	printf("\vExec exemple:\n./fractol mandelbrot\n./fractol julia (need more arguments - more examples below)\n./fractol burning\n");
	printf("\vCall Julia Fractal like this:\n./fractol julia \"-0.428 -0.580i\"\n./fractol julia -0.428 -0.580i\n");
}