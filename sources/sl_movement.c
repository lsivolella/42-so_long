/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:00:08 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 15:48:02 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_window_bounds(t_obj *obj)
{
	printf("Current Pos: (%d, %d)\n", obj->rect.pos.x, obj->rect.pos.y);
	printf("Movement Step: (%d, %d)\n", obj->move_dir.x, obj->move_dir.y);
	// Check left side
	if (obj->rect.pos.x <= 0 && obj->move_dir.x < 0)
	{
		printf("Cannot go left.\n");
		return FALSE;
	}
	// Check right side
	if (obj->rect.pos.x + obj->rect.width >= WIN_WIDTH
		&& obj->move_dir.x > 0)
	{
		printf("Cannot go right.\n");
		return FALSE;
	}
	// Check top side
	if (obj->rect.pos.y <= 0 && obj->move_dir.y < 0)
	{
		printf("Cannot go up.\n");
		return FALSE;
	}
	// Check bottom side
	if (obj->rect.pos.y + obj->rect.height >= WIN_HEIGHT
		&& obj->move_dir.y > 0)
	{
		printf("Cannot go down.\n");
		return FALSE;
	}
	printf("Free to move.\n");
	return (TRUE);
}

int	process_obj_movement(t_game *game, t_obj *obj)
{
	//printf("Process Movement");
	if (game->mlx_ptr == NULL)
		kill_program(game, e_mlx_null);
	if (obj == NULL)
		kill_program(game, e_obj_null);
	// verify collision here
	obj->move_dir = multi_xy(obj->move_dir, PLAYER_SPEED);
	if ((obj->move_dir.x != 0
		|| obj->move_dir.y != 0)
		&& check_window_bounds(obj))
			obj->rect.pos = add_vector(obj->rect.pos, obj->move_dir);
	obj->move_dir = VECTOR2_ZERO;
			
	return (0);
}