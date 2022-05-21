/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:20:32 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/21 11:34:06 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "key_mapping.h"
# include "error_handler.h"
# include "game_defs.h"
# include ".mlx.h"
// # include "X11/keysym.h"
// # include "X11/X.h"

/*
* Prototypes
*/

// sl_error_handler
void	get_error_arg(enum e_error_arg e_arg);
void	kill_program(t_game *game, int e_code);

#endif