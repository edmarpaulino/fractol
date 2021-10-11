/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:46 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 10:51:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define C_KEY 99
# define I_KEY 105
# define O_KEY 111

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_calc
{
	double	min;
	double	max;
	double	factor;
	double	c;
	double	z;
	double	pow2;
}				t_calc;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	int		i;
	int		max_i;
}				t_img;

typedef struct s_const
{
	double	real;
	double	im;
}				t_const;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*title;
	int		epa;
	t_img	img;
	t_calc	real;
	t_calc	im;
	t_const	c;
}				t_data;

int				ft_init_display(t_data *data);
int				ft_clear_memory(t_data *data);
void			ft_options_message(void);
void			ft_att_pixel(t_data *data, int color);
void			ft_init_mandelbrot(t_data *data);
void			ft_calc_mandelbrot(t_data *data);
void			ft_init_julia(t_data *data);
void			ft_calc_julia(t_data *data);
void			ft_init_burning_ship(t_data *data);
void			ft_calc_burning_ship(t_data *data);
void			ft_burning_ship(t_data *data);
unsigned int	ft_get_color(int n);
int				ft_put_image_to_window(t_data *data);
int				ft_key_select(int keycode, t_data *data);
int				ft_zoom(int keycode, int x, int y, t_data *data);

#endif
