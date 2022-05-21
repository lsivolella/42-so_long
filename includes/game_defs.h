/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:06:17 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/21 10:05:55 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DEFS_H
# define GAME_DEFS_H

/*
*	Macros 
*/
# define WIN_WIDTH 600
# define WIN_HEIGHT 300
# define WIN_NAME "game_window"
# define MLX_ERROR 1

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;

typedef struct s_obj
{
	
}	t_obj;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2

#endif