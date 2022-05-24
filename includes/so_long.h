/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:20:32 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 15:32:34 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "error_handler.h"
# include "game_defs.h"
# include "key_mapping.h"
# include "libft.h"
# include "mlx.h"

/* Prototypes */

/* sl_error_handler.c */
void	get_error_arg(t_error_arg e_arg);
void	kill_program(t_game *game, int e_code);

/* sl_initializers.c */
void	initialize_player(t_game *game);
void	initialize_img(t_game *game);
void	initialize_game_data(t_game *game);

/* sl_inputs.c */
int	close_window(t_game *game);
int	process_keypress(t_game *game);
void	handle_player_input(t_game *game, t_vector2 newPos);
int	handle_keypress(int keycode, t_game *game);

/* sl_map.c */

/* sl_movement.c */
t_bool	check_window_bounds(t_obj *obj);
int	process_obj_movement(t_game *game, t_obj *obj);

/* sl_render.c */
void	render_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
int	render_rect(t_img *img, t_rect rect);
int	render(t_game *game);

/* sl_trgb.c */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

/* sl_vector2_1.c */
t_vector2	add_vector(t_vector2 vector, t_vector2 new);
t_vector2	add_x(t_vector2 vector, int x);
t_vector2	add_y(t_vector2 vector, int y);
t_vector2	multi_xy(t_vector2 vector, int factor);

#endif