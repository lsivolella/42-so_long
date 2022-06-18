/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:09:45 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/28 17:00:38 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

typedef enum e_error_arg
{
	e_none				= 0,
	e_no_arg			= 1,
	e_invalid_arg		= 2,
	e_mlx_init			= 3,
	e_window_init		= 4,
	e_image_init		= 5,
	e_mlx_null			= 6,
	e_window_null		= 7,
	e_image_null		= 8,
	e_obj_null			= 9,
	e_unreadable_map	= 10,
	e_invalid_map		= 11
}	t_error_arg;

#endif