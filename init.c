/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:52:31 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/29 16:39:24 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_printf("Error with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->x_mov = 0.0;
	fractal->y_mov = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_key_hook(
		fractal->mlx_window,
		key_handler, // TODO
		fractal
	);
	
	mlx_mouse_hook(
		fractal->mlx_connection,
		mouse_handler,
		fractal
	);
	/*
	mlx_close_hook(
		fractal->mlx_connection,
		close_handler,
		fractal
	);
	*/
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_window = mlx_init(WIDTH, HEIGHT, fractal->name, 0);
	if (fractal->mlx_window == NULL)
	{
		malloc_error(); // como tratar esses erros?
	}
	fractal->mlx_image = mlx_new_image(fractal->mlx_window,
										WIDTH,
										HEIGHT);
	if (fractal->mlx_image == NULL)
	{
		mlx_close_window(fractal->mlx_window);
		free(fractal->mlx_window);
		malloc_error();
	}

	events_init(fractal);
	data_init(fractal);
}
