/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:08:17 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/29 15:04:27 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mandelbrot
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, +2, 0, WIDTH - 1) * fractal->zoom) + fractal->x_mov;
	c.y = (map(y, +2, -2, 0, HEIGHT - 1) * fractal->zoom) + fractal->y_mov;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		// the hyphotenuse is higher than the limit 
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
			mlx_put_pixel(fractal->mlx_image, x, y, color);
			return ;
		}
		i++;
	}
	// Point inside mandelbrot
	mlx_put_pixel(fractal->mlx_image, x, y, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_image_to_window(fractal->mlx_window,
						fractal->mlx_image,
						0,
						0);
}