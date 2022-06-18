/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/29 17:56:25 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector2	add_vector(t_vector2 vector, t_vector2 new)
{
	t_vector2	newVector;
	
	newVector.x = vector.x + new.x;
	newVector.y = vector.y + new .y;
	return newVector;
}

t_vector2	add_x(t_vector2 vector, int x)
{
	t_vector2	newVector;
	
	newVector.x = vector.x + x;
	newVector.y = vector.y;
	return newVector;
}

t_vector2	add_y(t_vector2 vector, int y)
{
	t_vector2	newVector;
	
	newVector.x = vector.x;
	newVector.y = vector.y + y;
	return newVector;
}

t_vector2	multi_vector(t_vector2 vector, int factor)
{
	t_vector2	newVector;
	
	newVector.x = vector.x * factor;
	newVector.y = vector.y * factor;
	return newVector;
}

t_vector2	multi_xy(t_vector2 vector, int x_factor, int y_factor)
{
	t_vector2	newVector;
	
	newVector.x = vector.x * x_factor;
	newVector.y = vector.y * y_factor;
	return newVector;
}
