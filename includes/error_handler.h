/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:09:45 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 12:22:33 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

typedef enum e_error_arg
{
	e_none				= 0,
	e_unknown_arg		= 1,
	e_mlx_init			= 2,
	e_window_init		= 3,
	e_image_init		= 4,
	e_mlx_null			= 5,
	e_window_null		= 6,
	e_image_null		= 7,
	e_obj_null			= 8,
	e_unknown_arg2		= 9,
	e_unknown_arg3		= 10
}	t_error_arg;

#endif