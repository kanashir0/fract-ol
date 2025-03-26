/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:52:31 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/26 17:50:55 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static void	malloc_error(void)
// {
// 	ft_printf("Error with malloc");
// 	exit(EXIT_FAILURE);
// }

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, 0);
	// if (fractal->mlx_connection == NULL)
	// 	malloc_error(); // TODO
	// fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
	// 									WIDTH,
	// 									HEIGHT,
	// 									fractal->name);
	// if (fractal->mlx_window == NULL)
	// {
	// 	mlx_destroy_display(fractal->mlx_connection);
	// 	free(fractal->mlx_connection);
	// 	malloc_error();
	// }
	// fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
	// 									WIDTH,
	// 									HEIGHT);
	// if (fractal->img.img_ptr == NULL)
	// {
	// 	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	// 	mlx_destroy_display(fractal->mlx_connection);
	// 	free(fractal->mlx_connection);
	// 	malloc_error();
	// }
	// fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
	// 											&fractal->img.bpp,
	// 											&fractal->img.line_len,
	// 											&fractal->img.endian);
	// TODO events_hook_init()
	// TODO data_init()
}