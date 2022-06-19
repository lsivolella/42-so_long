/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:20:32 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 11:19:52 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/resource.h> // for RLIMIT_NOFILE
# include "error_handler.h"
# include "game_defs.h"
# include "key_mapping.h"
# include "libft.h"
# include "mlx.h"
# include <time.h> // for time counter

# define BUFFER_SIZE 1000

/* Prototypes */

/* get_next_line */
int			get_next_line(int fd, char **line);

/* sl_error_handler.c */
void		get_error_arg(t_error_arg e_arg);
void		free_map(char **map);
void		soft_kill_program(int e_code);
void		kill_program_on_validate(t_map *map, int e_code);
void		kill_program(t_game *game, int e_code);

/* sl_grid */
t_vector	world_to_grid_pos(t_vector pos);
t_vector	get_obj_world_center(t_obj obj);
t_vector	get_obj_grid_center(t_obj obj);
void		print_map(t_map *map);

/* sl_inputs.c */
int			close_window(t_game *game);
int			handle_keypress(int keycode, t_game *game);

/* sl_map_read.c */
void		handle_map(int argc, char **argv, t_game *game);

/* sl_map_validate.c */
void		validate_map(t_map *map);

/* sl_movement.c */
int			process_obj_movement(t_game *game, t_obj *obj);

/* sl_render.c */
t_img		create_sprite(t_game *game, t_img *src, char *address);
int			handle_map_rendering(t_game *game);

/* sl_setups.c */
void		setup_game(t_game *game);

/* sl_utils.c */
void		print_moves(t_game *game);
char		*get_player_sprite(t_obj *player);

/* sl_vector_1.c */
t_vector	add_vector(t_vector vector, t_vector new);
t_vector	add_x(t_vector vector, int x);
t_vector	add_y(t_vector vector, int y);
t_vector	multi_vector(t_vector vector, int factor);
t_vector	multi_xy(t_vector vector, int x_factor, int y_factor);

/* sl_vector_2.c */
t_vector	vector_zero(void);
t_vector	vector_left(void);
t_vector	vector_up(void);
t_vector	vector_right(void);
t_vector	vector_down(void);

/* sl_vector_3.c */
t_bool		vector_equals(t_vector vector_a, t_vector vector_b);
void		delay(int milliseconds);
#endif