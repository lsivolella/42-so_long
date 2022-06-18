/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:26:59 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 18:01:51 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_vector	world_to_grid_pos(t_vector pos)
{
	t_vector	grid_pos;

	grid_pos = (t_vector){pos.x / GRID_X, pos.y / GRID_Y};
	return (grid_pos);
}

t_vector	get_obj_world_center(t_obj obj)
{
	t_vector	center;

	center = (t_vector){obj.pos.x + (GRID_X / 2), obj.pos.y + (GRID_Y / 2)};
	return (center);
}

t_vector	get_obj_grid_center(t_obj obj)
{
	t_vector	center;

	center = (t_vector){(obj.pos.x + (GRID_X / 2)) / GRID_X,
		(obj.pos.y + (GRID_Y / 2)) / GRID_Y};
	return (center);
}

void	print_map(t_map *map)
{
	int		i;

	i = -1;
	ft_putstr_fd("Start printing map\n", 1);
	while (map->map[++i] != NULL)
	{
		printf("Line: %d ->", i);
		printf("%s\n", map->map[i]);
	}
	ft_putstr_fd("Finished printing map\n", 1);
}
