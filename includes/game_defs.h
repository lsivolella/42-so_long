/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:06:17 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 11:20:46 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DEFS_H
# define GAME_DEFS_H

/*	Macros */

/* General */
# define WIN_WIDTH 1200
# define WIN_HEIGHT 600
# define GRID_X 64
# define GRID_Y 64
# define WIN_NAME "game_window"
# define MLX_ERROR 1

/* Player */
# define PLAYER_SPEED 16

/* Colors */
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0xFF00
# define COLOR_BLACK 0x000000

/* Map */
# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'

/* Sprites */
# define S_PLAYER_UP_00 "sprites/link/link_up_00.xpm"
# define S_PLAYER_UP_01 "sprites/link/link_up_01.xpm"
# define S_PLAYER_DOWN_00 "sprites/link/link_down_00.xpm"
# define S_PLAYER_DOWN_01 "sprites/link/link_down_01.xpm"
# define S_PLAYER_RIGHT_00 "sprites/link/link_right_00.xpm"
# define S_PLAYER_RIGHT_01 "sprites/link/link_right_01.xpm"
# define S_PLAYER_LEFT_00 "sprites/link/link_left_00.xpm"
# define S_PLAYER_LEFT_01 "sprites/link/link_left_01.xpm"
# define S_WALL "sprites/wall/wall_00.xpm"
# define S_FLOOR "sprites/floor/floor_00.xpm"
# define S_COLLECTIBLE "sprites/collectible/collectible_00.xpm"
# define S_EXIT "sprites/exit/exit_00.xpm"

typedef enum e_bool
{
	FALSE	= 0,
	TRUE	= 1
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*mlx_img;
	char		*pixels;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector	size;
}	t_img;

typedef struct s_rect
{
	int			width;
	int			height;
	int			color;
	t_vector	pos;
}	t_rect;

typedef struct s_obj
{
	int			move_speed;
	t_vector	move_dir;
	t_vector	last_move;
	t_vector	pos;
	t_img		sprite;
	t_bool		switch_sptr;
}	t_obj;

typedef struct s_map
{
	char		**map;
	int			n_player;
	int			n_exits;
	int			n_collectibles;
	t_img		wall;
	t_img		floor;
	t_img		collectible;
	t_img		exit;
	t_vector	grid_size;
	t_vector	player_init;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_img		img;
	t_obj		player;
	t_vector	win_size;
	int			move_counter;
}	t_game;

#endif
