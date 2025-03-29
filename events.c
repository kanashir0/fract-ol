/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:08:53 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/29 16:39:22 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_handler(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	mlx_close_window(fractal->mlx_window); //look docs for mlx_terminate()
	// free(conn);
	exit(EXIT_SUCCESS);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handler(fractal);
	else if (keydata.key == MLX_KEY_LEFT)
		fractal->x_mov -= 0.25;
	else if (keydata.key == MLX_KEY_RIGHT)
		fractal->x_mov += 0.25;
	else if (keydata.key == MLX_KEY_UP)
		fractal->y_mov += 0.25;
	else if (keydata.key == MLX_KEY_DOWN)
		fractal->y_mov -= 0.25;
	// else if (keydata.key == MLX_KEY_EQUAL) // validate this key
		
	// else if (keydata.key == MLX_KEY_MINUS)

	ft_printf("%d\n", keydata.key);
	fractal_render(fractal);
	return ;
}

void	mouse_handler(mlx_mouse)