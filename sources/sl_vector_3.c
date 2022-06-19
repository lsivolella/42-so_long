/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/19 11:12:53 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	vector_equals(t_vector vector_a, t_vector vector_b)
{
	if (vector_a.x == vector_b.x
		&& vector_a.y == vector_b.y)
		return (TRUE);
	else
		return (FALSE);
}

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}
