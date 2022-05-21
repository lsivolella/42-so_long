/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:09:45 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/21 10:17:39 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

enum	e_error_arg
{
	e_none				= 1<<0,
	e_unknown_arg		= 1<<1,
	e_mlx_init_error	= 1<<2,
	e_mlx_window_error	= 1<<3,
	e_mlx_image_error	= 1<<4,
	e_unknown_arg1		= 1<<5,
	e_unknown_arg2		= 1<<6,
	e_unknown_arg3		= 1<<7
};

#endif