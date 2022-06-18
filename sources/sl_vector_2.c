/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:56:46 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	vector_zero(void)
{
	return ((t_vector){0, 0});
}

t_vector	vector_left(void)
{
	return ((t_vector){-1, 0});
}

t_vector	vector_up(void)
{
	return ((t_vector){0, 1});
}

t_vector	vector_right(void)
{
	return ((t_vector){1, 0});
}

t_vector	vector_down(void)
{
	return ((t_vector){0, -1});
}
