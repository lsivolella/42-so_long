/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:15:08 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 10:47:33 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	kill_program(game, e_none);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == key_esc)
	{
		kill_program(game, e_none);
	}
	if (keycode == key_left || keycode == key_a)
	{
		game->player.move_dir = vector_left();
	}
	if (keycode == key_up || keycode == key_w)
	{
		game->player.move_dir = vector_down();
	}
	if (keycode == key_right || keycode == key_d)
	{
		game->player.move_dir = vector_right();
	}
	if (keycode == key_down || keycode == key_s)
	{
		game->player.move_dir = vector_up();
	}
	process_obj_movement(game, &game->player);
	return (0);
}
