/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:45:04 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 11:20:45 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*str;
	int		half_win_size;
	int		i;
	int		j;

	str = ft_itoa(game->move_counter);
	half_win_size = game->win_size.x / 2;
	j = GRID_Y / 4;
	while (j < GRID_Y * 3 / 4)
	{
		i = half_win_size - 50;
		while (i < (half_win_size + 50))
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, j, COLOR_BLACK);
			i++;
		}
		j++;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		half_win_size - 35, 32 + 5, COLOR_WHITE, "Movement: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		half_win_size + 25, 32 + 5, COLOR_WHITE, str);
	free(str);
}

static char	*get_horizontal_sprite(t_obj player)
{
	if (player.move_dir.x > 0)
	{
		if (!player.switch_sptr)
			return (S_PLAYER_RIGHT_00);
		else
			return (S_PLAYER_RIGHT_01);
	}
	else if (player.move_dir.x < 0)
	{
		if (!player.switch_sptr)
			return (S_PLAYER_LEFT_00);
		else
			return (S_PLAYER_LEFT_01);
	}
	return (NULL);
}

static char	*get_vertical_sprite(t_obj player)
{
	if (player.move_dir.y > 0)
	{
		if (!player.switch_sptr)
			return (S_PLAYER_DOWN_00);
		else
			return (S_PLAYER_DOWN_01);
	}
	else if (player.move_dir.y < 0)
	{
		if (!player.switch_sptr)
			return (S_PLAYER_UP_00);
		else
			return (S_PLAYER_UP_01);
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
	player->switch_sptr = !player->switch_sptr;
	return (sprite);
}
