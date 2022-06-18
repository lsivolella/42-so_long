/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:38:49 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:50:28 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*dest;

	total_size = nmemb * size;
	dest = malloc(total_size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, total_size);
	return (dest);
}
