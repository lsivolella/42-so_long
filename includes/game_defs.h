/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:06:17 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 15:43:40 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DEFS_H
# define GAME_DEFS_H

/*	Macros */

/* General */
# define WIN_WIDTH 600
# define WIN_HEIGHT 300
# define WIN_NAME "game_window"
# define MLX_ERROR 1

/* Player */
# define PLAYER_SPEED 5

/* Colors */
# define WHITE_PIXEL 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

/* Vectors */
# define VECTOR2_ZERO (t_vector2){0 , 0}
# define VECTOR2_LEFT (t_vector2){-1 , 0}
# define VECTOR2_UP (t_vector2){0 , 1}
# define VECTOR2_RIGHT (t_vector2){1 , 0}
# define VECTOR2_DOWN (t_vector2){0 , -1}

typedef enum e_bool
{
	FALSE	= 0,
	TRUE	= 1
}	t_bool;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_rect
{
	t_vector2	pos;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_obj
{
	t_vector2	move_dir;
	int			move_speed;
	t_rect		rect;
}	t_obj;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_obj	player;
}	t_game;

#endif
