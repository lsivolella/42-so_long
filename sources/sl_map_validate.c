/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:18:33 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 14:08:54 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	validate_walls(t_map *map)
{
	int	i;
	int	j;
	int	line_length;

	i = -1;
	while (map->map[++i])
	{
		line_length = ft_strlen(map->map[i]);
		if (line_length <= 0)
			return (0);
		if (map->map[i][0] != MAP_WALL
			|| map->map[i][line_length - 1] != MAP_WALL)
			return (0);
		if (i == 0 || map->map[i + 1] == NULL)
		{
			j = -1;
			while (map->map[i][++j] != '\0')
				if (map->map[i][j] != MAP_WALL)
					return (0);
		}
	}
	map->grid_size = (t_vector){line_length, i};
	return (1);
}

static int	validate_geometry(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
	{
		if (ft_strlen(map->map[0]) != ft_strlen(map->map[i]))
			return (0);
	}
	return (1);
}

static	int	validate_components(t_map *map)
{
	int		i;
	int		j;
	char	chr;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j] != '\0')
		{
			chr = map->map[i][j];
			if (chr == MAP_PLAYER)
			{
				map->player_init = (t_vector){j, i};
				map->n_player++;
			}
			else if (chr == MAP_COLLECTIBLE)
				map->n_collectibles++;
			else if (chr == MAP_EXIT)
				map->n_exits++;
		}
	}
	if (map->n_player != 1 || map->n_exits < 1 || map->n_collectibles < 1)
		return (0);
	return (1);
}

static int	validate_chars(char **map)
{
	int		i;
	int		j;
	char	chr;

	i = -1;
	if (map == NULL)
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			chr = map[i][j];
			if (chr != MAP_PLAYER && chr != MAP_COLLECTIBLE
				&& chr != MAP_WALL && chr != MAP_FLOOR
				&& chr != MAP_EXIT)
				return (0);
		}
	}
	return (1);
}

void	validate_map(t_map *map)
{
	if (map == NULL || map->map == NULL)
		soft_kill_program(e_invalid_map);
	if (!validate_chars(map->map))
	{
		kill_program_on_validate(map, e_invalid_map);
	}
	if (!validate_components(map))
	{
		kill_program_on_validate(map, e_invalid_map);
	}
	if (!validate_geometry(map))
	{
		kill_program_on_validate(map, e_invalid_map);
	}
	if (!validate_walls(map))
	{
		kill_program_on_validate(map, e_invalid_map);
	}
}
