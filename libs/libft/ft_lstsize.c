/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:13:15 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/08 14:16:39 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*current;

	counter = 0;
	current = lst;
	if (!lst)
		return (counter);
	while (current != NULL)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}
