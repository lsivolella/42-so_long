/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vector_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 18:05:38 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	add_vector(t_vector vector, t_vector new)
{
	t_vector	new_vector;

	new_vector.x = vector.x + new.x;
	new_vector.y = vector.y + new .y;
	return (new_vector);
}

t_vector	add_x(t_vector vector, int x)
{
	t_vector	new_vector;

	new_vector.x = vector.x + x;
	new_vector.y = vector.y;
	return (new_vector);
}

t_vector	add_y(t_vector vector, int y)
{
	t_vector	new_vector;

	new_vector.x = vector.x;
	new_vector.y = vector.y + y;
	return (new_vector);
}

t_vector	multi_vector(t_vector vector, int factor)
{
	t_vector	new_vector;

	new_vector.x = vector.x * factor;
	new_vector.y = vector.y * factor;
	return (new_vector);
}

t_vector	multi_xy(t_vector vector, int x_factor, int y_factor)
{
	t_vector	new_vector;

	new_vector.x = vector.x * x_factor;
	new_vector.y = vector.y * y_factor;
	return (new_vector);
}
