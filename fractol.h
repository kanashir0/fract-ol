/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:39:58 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/29 15:01:03 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

// Window size
# define WIDTH	800
# define HEIGHT	800

// Colors
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_window;
	void	*mlx_image;
	double	escape_value;
	int		iterations_definition;
	double	x_mov;
	double	y_mov;
	double	zoom;
}				t_fractal;

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

// Math utils
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// Event handlers
void	key_handler(mlx_key_data_t keydata, void *param);

#endif