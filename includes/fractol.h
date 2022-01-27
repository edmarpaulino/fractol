/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:54:46 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/27 19:41:42 by edpaulin         ###   ########.fr       */
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

# define ERROR_1 "./messages/error_journey_without_a_destination.txt"
# define ERROR_2 "./messages/error._invalid_coordinates.txt"
# define HELP "./messages/help.txt"

# define SUCCESS 1
# define ERROR -1

# define TRUE 1
# define FALSE 0

# define FEW_ARGS 1
# define INVALID_ARGS 2

# define MAX_I 300
# define SPEED 0.02

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define C_KEY 99
# define C_KEY_WSL 106

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ZOOM_IN 1
# define ZOOM_OUT -1

typedef struct s_color
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_color;

typedef struct s_zoom
{
	double	x_ratio;
	double	y_ratio;
	double	delta_re;
	double	delta_im;
	double	delta_delta_re;
	double	delta_delta_im;
}				t_zoom;

typedef struct s_calc
{
	double	min;
	double	max;
	double	factor;
	double	c;
	double	z;
	double	z_pow2;
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
	int		pixel_color;
}				t_img;

typedef struct s_const
{
	char	**coor;
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
	char	fractal;
	char	color;
	t_img	img;
	t_calc	real;
	t_calc	im;
	t_const	cons;
}				t_data;

void	ft_init(int argc, char **argv, t_data *data);
void	ft_init_pointers(t_data *data);
void	ft_create_display(t_data *data);
void	ft_create_fractal(t_data *data);
void	ft_draw_fractal(t_data *data);
int		ft_att_screen(t_data *data);
void	ft_att_factor(t_data *data);
void	ft_att_z_value(t_data *data);
void	ft_att_pixel(t_data *data, int color);
int		ft_key_select(int keycode, t_data *data);
int		ft_zoom(int keycode, int x, int y, t_data *data);
void	ft_error_message(int error_type);
int		ft_clear_memory(t_data *data, int status);

#endif
