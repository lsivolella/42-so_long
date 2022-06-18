/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:07:55 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:45:10 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_error_arg(t_error_arg e_arg)
{
	if (e_arg == e_none)
	{
		ft_putstr_fd("Exited with no errors.\n", 1);
		return ;
	}
	ft_putstr_fd("Error\n", 1);
	if (e_arg == e_no_arg)
		ft_putstr_fd("No arguments detected.\n", 1);
	else if (e_arg == e_invalid_arg)
		ft_putstr_fd("Invalid argument detected.\n", 1);
	else if (e_arg == e_mlx_init)
		ft_putstr_fd("Could not initialize MinilibX.\n", 1);
	else if (e_arg == e_window_init)
		ft_putstr_fd("Could not instantiate a MinilibX window.\n", 1);
	else if (e_arg == e_image_init)
		ft_putstr_fd("Could not render a MinilibX image.\n", 1);
	else if (e_arg == e_mlx_null)
		ft_putstr_fd("Could not proceed. Connection has been lost.\n", 1);
	else if (e_arg == e_obj_null)
		ft_putstr_fd("Attempting to modify a null object.\n", 1);
	else if (e_arg == e_unreadable_map)
		ft_putstr_fd("Could not read map file.\n", 1);
	else if (e_arg == e_invalid_map)
		ft_putstr_fd("Map is invalid.\n", 1);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	soft_kill_program(int e_code)
{
	get_error_arg(e_code);
	exit(e_code);
}

void	kill_program_on_validate(t_map *map, int e_code)
{
	free_map(map->map);
	soft_kill_program(e_code);
}

void	kill_program(t_game *game, int e_code)
{
	mlx_loop_end(game->mlx_ptr);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.wall.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->map.floor.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->map.collectible.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->map.exit.mlx_img);
	free_map(game->map.map);
	mlx_destroy_image(game->mlx_ptr, game->player.sprite.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	soft_kill_program(e_code);
}
