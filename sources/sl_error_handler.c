/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:07:55 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/21 10:29:56 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_error_arg(enum e_error_arg e_arg)
{
	if (e_arg == e_none)
	{
		printf("Program terminated with success.\n");
		return;
	}
	else if (e_arg == e_unknown_arg)
	{
		printf("Unknown arg detected.\n");
	}
	else if (e_arg == e_mlx_init_error)
	{
		printf("Could not initialize MinilibX.\n");
	}
	else if (e_arg == e_mlx_window_error)
	{
		printf("Could not instantiate a MinilibX window.\n");
	}
	else if (e_arg == e_mlx_image_error)
	{
		printf("Could not render a MinilibX image.\n");
	}
	printf("Terminating program.\n");
}

void	kill_program(t_game *game, int e_code)
{
	if (game->win_ptr)
	{
		// method already frees win_ptr
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	get_error_arg(e_code);
}
