/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:11:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/29 17:40:27 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(char *path, t_map *map)
{
	int		fd;
	int		read_return;
	char	*line;
	int		i;

	if (path == NULL)
		soft_kill_program(e_unreadable_map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		soft_kill_program(e_unreadable_map);
	map->map = (char **)calloc(1000, sizeof(char *));
	read_return = 1;
	i = 0;
	while (read_return > 0)
	{
		line = NULL;
		read_return = get_next_line(fd, &line);
		if (line != NULL)
			map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
}

static void	parse_map(int argc, char **argv, t_game *game)
{
	if (argc < 2)
		soft_kill_program(e_no_arg);
	else if (ft_strstr(argv[1], ".ber") == 0)
		soft_kill_program(e_invalid_arg);
	else
		read_map(argv[1], &game->map);
}

void	handle_map(int argc, char **argv, t_game *game)
{
	parse_map(argc, argv, game);
	validate_map(&game->map);
}
