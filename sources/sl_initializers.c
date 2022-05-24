/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:11:16 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 15:43:56 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_player(t_game *game)
{
	t_obj	player;

	player.move_dir = VECTOR2_ZERO;
	player.move_speed = PLAYER_SPEED;
	player.rect = (t_rect)
	{
		(t_vector2){0, WIN_HEIGHT - 100},
		100,
		100,
		create_trgb(255, 0, 0, 0)
	};
	game->player = player;
}

void	initialize_img(t_game *game)
{
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
}

void	initialize_game_data(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	initialize_img(game);
	initialize_player(game);
}
