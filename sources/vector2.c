/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/21 10:10:45 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector2	add_x(t_vector2 vector, int x)
{
	int			newX;
	t_vector2	newVector;
	
	newX = vector.x + x;
	newVector.x = newX;
	newVector.y = vector.y;
	return newVector;
}
