/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:11:16 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/29 17:34:56 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector2	initialize_vector2(void)
{
	t_vector2	vector;

	ft_memset(&vector, '\0', sizeof(t_vector2));
	return (vector);
}

t_map	initialize_map(void)
{
	t_map	map;

	ft_memset(&map, '\0', sizeof(t_map));
	return (map);
}

t_obj	initialize_obj(void)
{
	t_obj	obj;

	ft_memset(&obj, '\0', sizeof(t_obj));
	return (obj);
}

t_rect	initialize_rect(void)
{
	t_rect	rect;

	ft_memset(&rect, '\0', sizeof(t_rect));
	return (rect);
}

t_img	initialize_img(void)
{
	t_img	img;

	ft_memset(&img, '\0', sizeof(t_img));
	return (img);
}

t_game	initialize_game(void)
{
	t_game	game;
	
	ft_memset(&game, '\0', sizeof(t_game));
	ft_memset(&game.img, '\0', sizeof(t_img));
	ft_memset(&game.map, '\0', sizeof(t_map));
	ft_memset(&game.player, '\0', sizeof(t_obj));
	ft_memset(&game.win_size, '\0', sizeof(t_vector2));
	return (game);
}
