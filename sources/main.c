/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:21:42 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 18:00:18 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	game_logic(t_game *game, t_map *map, t_obj player)
{
	t_vector	player_grid_center;

	player_grid_center = get_obj_grid_center(player);
	if (map->map[player_grid_center.y]
		[player_grid_center.x] == MAP_COLLECTIBLE)
	{
		game->map.n_collectibles--;
		map->map[player_grid_center.y][player_grid_center.x] = MAP_FLOOR;
	}
	else if (map->map[player_grid_center.y]
		[player_grid_center.x] == MAP_EXIT
		&& game->map.n_collectibles == 0)
	{
		kill_program(game, e_none);
	}
	game->player.move_dir = vector_zero();
	return (e_none);
}

static int	game_loop(t_game *game)
{
	handle_map_rendering(game);
	game_logic(game, &game->map, game-> player);
	return (0);
}

static t_game	initialize_structs(void)
{
	t_game	game;

	ft_memset(&game, '\0', sizeof(t_game));
	ft_memset(&game.img, '\0', sizeof(t_img));
	ft_memset(&game.map, '\0', sizeof(t_map));
	ft_memset(&game.player, '\0', sizeof(t_obj));
	ft_memset(&game.win_size, '\0', sizeof(t_vector));
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = initialize_structs();
	handle_map(argc, argv, &game);
	setup_game(&game);
	mlx_loop_hook(game.mlx_ptr, &game_loop, &game);
	mlx_hook(game.win_ptr, on_destroy, mask_no_event, &close_window, &game);
	mlx_hook(game.win_ptr, on_keydown, mask_key_press, &handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
