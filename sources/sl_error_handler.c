/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:07:55 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 12:20:19 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_error_arg(t_error_arg e_arg)
{
	if (e_arg == e_none)
	{
		printf("Exited with no errors.\n");
	}
	else if (e_arg == e_unknown_arg)
	{
		printf("Unknown arg detected.\n");
	}
	else if (e_arg == e_mlx_init)
	{
		printf("Could not initialize MinilibX.\n");
	}
	else if (e_arg == e_window_init)
	{
		printf("Could not instantiate a MinilibX window.\n");
	}
	else if (e_arg == e_image_init)
	{
		printf("Could not render a MinilibX image.\n");
	}
	else if (e_arg == e_mlx_null)
	{
		printf("Could not proceed. Connection instance has been lost.\n");
	}
		else if (e_arg == e_obj_null)
	{
		printf("Error: Attempting to modify a null object.\n");
	}
	printf("Terminating program.\n");
}

void	kill_program(t_game *game, int e_code)
{
	mlx_loop_end(game->mlx_ptr);
	if (game->img.mlx_img)
	{
		printf("MLX Destroy Image\n");
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	}
	if (game->win_ptr)
	{
		printf("MLX Destroy Window\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (game->mlx_ptr)
	{
		printf("MLX Destroy Display\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	get_error_arg(e_code);
	printf("Killed program.\n");
	exit(e_code);
}
