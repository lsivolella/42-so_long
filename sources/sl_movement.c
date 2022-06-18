/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:00:08 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 18:03:30 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_hor_corner_check(t_obj obj, t_vector *c_a, t_vector *c_b)
{
	t_vector	pos;

	pos = (t_vector){obj.pos.x + obj.move_dir.x,
		obj.pos.y + obj.move_dir.y};
	if (obj.move_dir.x < 0)
	{
		*c_a = world_to_grid_pos((t_vector){pos.x + 1, pos.y + 1});
		*c_b = world_to_grid_pos((t_vector)
			{pos.x + 1, pos.y + GRID_Y - 1});
	}
	else if (obj.move_dir.x > 0)
	{
		*c_a = world_to_grid_pos((t_vector)
			{pos.x + GRID_X - 1, pos.y + 1});
		*c_b = world_to_grid_pos((t_vector)
			{pos.x + GRID_X - 1, pos.y + GRID_Y - 1});
	}
}

static void	move_vert_corner_check(t_obj obj, t_vector *c_a, t_vector *c_b)
{
	t_vector	pos;

	pos = (t_vector){obj.pos.x + obj.move_dir.x,
		obj.pos.y + obj.move_dir.y};
	if (obj.move_dir.y < 0)
	{
		*c_a = world_to_grid_pos((t_vector){pos.x + 1, pos.y + 1});
		*c_b = world_to_grid_pos((t_vector)
			{pos.x + GRID_X - 1, pos.y + 1});
	}
	else if (obj.move_dir.y > 0)
	{
		*c_a = world_to_grid_pos((t_vector)
			{pos.x + 1, pos.y + GRID_Y - 1});
		*c_b = world_to_grid_pos((t_vector)
			{pos.x + GRID_X - 1, pos.y + GRID_Y - 1});
	}
}

static t_bool	check_walls(t_game game, t_map map, t_obj obj)
{
	t_vector	new_pos;
	t_vector	corner_a;
	t_vector	corner_b;

	new_pos = (t_vector){obj.pos.x + obj.move_dir.x,
		obj.pos.y + obj.move_dir.y};
	if (new_pos.x < 0 || new_pos.y < 0
		|| (new_pos.x + obj.sprite.size.x) > game.win_size.x
		|| (new_pos.y + obj.sprite.size.y) > game.win_size.y)
		return (FALSE);
	if (obj.move_dir.x != 0)
		move_hor_corner_check(obj, &corner_a, &corner_b);
	else if (obj.move_dir.y != 0)
		move_vert_corner_check(obj, &corner_a, &corner_b);
	if (map.map[corner_a.y][corner_a.x] == MAP_WALL
	|| map.map[corner_b.y][corner_b.x] == MAP_WALL)
		return (FALSE);
	return (TRUE);
}

int	process_obj_movement(t_game *game, t_obj *obj)
{
	if (game->mlx_ptr == NULL)
		kill_program(game, e_mlx_null);
	if (obj == NULL)
		kill_program(game, e_obj_null);
	obj->move_dir = multi_vector(obj->move_dir, PLAYER_SPEED);
	if ((obj->move_dir.x != 0 || obj->move_dir.y != 0)
		&& check_walls(*game, (*game).map, *obj))
	{
		obj->pos = add_vector(obj->pos, obj->move_dir);
		game->move_counter++;
		ft_putstr_fd("\rMovements: ", 1);
		ft_putnbr_fd(game->move_counter, 1);
	}
	return (0);
}
