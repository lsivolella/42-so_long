/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:11 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:56:43 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	setup_map(t_game *game, t_map *map)
{
	map->wall = create_sprite(game, &map->wall, S_WALL);
	map->floor = create_sprite(game, &map->floor, S_FLOOR);
	map->collectible = create_sprite(game, &map->floor, S_COLLECTIBLE);
	map->exit = create_sprite(game, &map->floor, S_EXIT);
}

static void	setup_player(t_game *game, t_map *map)
{
	t_obj	player;

	player = game->player;
	player.sprite = create_sprite(game, &player.sprite, S_PLAYER_DOWN);
	player.move_dir = vector_zero();
	player.pos = multi_xy(map->player_init, GRID_X, GRID_Y);
	player.move_speed = PLAYER_SPEED;
	game->player = player;
}

static void	setup_window_size(t_game *game, t_map *map)
{
	game->win_size.x = GRID_X * map->grid_size.x;
	game->win_size.y = GRID_Y * map->grid_size.y;
}

/**
 * @brief Describe method
 * @param game Describe parameter
 * @return Describe return
 **/
void	setup_game(t_game *game)
{
	setup_window_size(game, &game->map);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		kill_program(game, e_mlx_init);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->win_size.x, game->win_size.y, WIN_NAME);
	if (game->win_ptr == NULL)
		kill_program(game, e_window_init);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr,
			game->win_size.x, game->win_size.y);
	if (game->img.mlx_img == NULL)
		kill_program(game, e_image_init);
	game->img.pixels = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	setup_player(game, &game->map);
	setup_map(game, &game->map);
}
