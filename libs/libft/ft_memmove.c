/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:34:43 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/01 09:31:27 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;

	if (!dest && !src)
		return (NULL);
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (dest > src)
	{
		newdest += n;
		newsrc += n;
		while (n--)
			*(--newdest) = *(--newsrc);
	}
	else
	{	
		while (n--)
			*(newdest++) = *(newsrc++);
	}	
	return (dest);
}
