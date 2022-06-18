/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:55:57 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/07 12:04:01 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;
	char	search;

	i = 0;
	src = (char *)s;
	search = c;
	while (src[i] != '\0' && src[i] != search)
		i++;
	if (src[i] == search)
		return ((char *)src + i);
	return (NULL);
}
