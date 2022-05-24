/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:15:08 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 15:45:44 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	kill_program(game, e_none);
	return (0);
}

int	process_keypress(t_game *game)
{
	process_obj_movement(game, &game->player);
	return (0);
}

void	handle_player_input(t_game *game, t_vector2 newPos)
{
	game->player.move_dir = multi_xy(newPos, PLAYER_SPEED);
}

int	handle_keypress(int keycode, t_game *game)
{
	printf("Key Code: %d\n", keycode);
	if (keycode == key_esc)
	{
		kill_program(game, e_none);
	}
	if (keycode == key_left)
	{
		game->player.move_dir = VECTOR2_LEFT;
	}
	if (keycode == key_up)
	{
		game->player.move_dir = VECTOR2_DOWN;
	}
	if (keycode == key_right)
	{
		game->player.move_dir = VECTOR2_RIGHT;
	}
	if (keycode == key_down)
	{
		game->player.move_dir = VECTOR2_UP;
	}
	process_keypress(game);
	return (0);
}
