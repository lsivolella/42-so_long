/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:55:49 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:55:28 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_sprite(t_game *game, t_img *src, char *address)
{
	t_img	img;

	img = *src;
	img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, address,
			&img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.mlx_img, &img.bpp,
			&img.line_len, &img.bpp);
	return (img);
}

static void	render_player(t_game *game, t_obj *player)
{
	if (player->move_dir.x != 0 || player->move_dir.y != 0)
		mlx_destroy_image(game->mlx_ptr, player->sprite.mlx_img);
	if (player->move_dir.x != 0 && player->move_dir.y == 0)
	{
		if (player->move_dir.x > 0)
			player->sprite = create_sprite(game, &player->sprite,
					S_PLAYER_RIGHT);
		else if (player->move_dir.x < 0)
			player->sprite = create_sprite(game, &player->sprite,
					S_PLAYER_LEFT);
	}
	else if (player->move_dir.x == 0 && player->move_dir.y != 0)
	{
		if (player->move_dir.y > 0)
			player->sprite = create_sprite(game, &player->sprite,
					S_PLAYER_DOWN);
		else if (player->move_dir.y < 0)
			player->sprite = create_sprite(game, &player->sprite, S_PLAYER_UP);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		player->sprite.mlx_img, player->pos.x, player->pos.y);
}

static void	render_map(t_game *game, t_map *map, t_vector grid)
{
	if (map->map[grid.y][grid.x] == MAP_WALL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			map->wall.mlx_img, grid.x * GRID_X, grid.y * GRID_Y);
	}
	else if (map->map[grid.y][grid.x] == MAP_FLOOR
		|| map->map[grid.y][grid.x] == MAP_PLAYER)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			map->floor.mlx_img, grid.x * GRID_X, grid.y * GRID_Y);
	}
	else if (map->map[grid.y][grid.x] == MAP_COLLECTIBLE)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			map->collectible.mlx_img, grid.x * GRID_X, grid.y * GRID_Y);
	}
	else if (map->map[grid.y][grid.x] == MAP_EXIT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			map->exit.mlx_img, grid.x * GRID_X, grid.y * GRID_Y);
	}
}

int	handle_map_rendering(t_game *game)
{
	t_vector	grid;

	grid = (t_vector){-1, -1};
	if (game->win_ptr == NULL)
		kill_program(game, e_window_null);
	while (game->map.map[++grid.y])
	{
		while (game->map.map[grid.y][++grid.x])
		{
			render_map(game, &game->map, grid);
			render_player(game, &game->player);
		}
		grid.x = -1;
	}
	return (e_none);
}
