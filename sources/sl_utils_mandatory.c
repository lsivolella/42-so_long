/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_mandatory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:45:04 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 11:39:09 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	if (vector_equals(vector_zero(), game->player.move_dir))
		return ;
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->move_counter, 1);
}

static char	*get_horizontal_sprite(t_obj player)
{
	if (player.move_dir.x > 0)
	{
		return (S_PLAYER_RIGHT_00);
	}
	else if (player.move_dir.x < 0)
	{
		return (S_PLAYER_LEFT_00);
	}
	return (NULL);
}

static char	*get_vertical_sprite(t_obj player)
{
	if (player.move_dir.y > 0)
	{
		return (S_PLAYER_DOWN_00);
	}
	else if (player.move_dir.y < 0)
	{
		return (S_PLAYER_UP_00);
	}
	return (NULL);
}

char	*get_player_sprite(t_obj *player)
{
	char	*sprite;

	sprite = S_PLAYER_DOWN_00;
	if (player->move_dir.x != 0 && player->move_dir.y == 0)
		sprite = get_horizontal_sprite(*player);
	else if (player->move_dir.x == 0 && player->move_dir.y != 0)
		sprite = get_vertical_sprite(*player);
	return (sprite);
}
