/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:48:50 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/08 17:07:48 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] != '\0' && (i + j) < len)
	{
		while (big[i] != little[j] && big[i] != '\0')
			i++;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
			if (big[i + j] != little[j] && little[j] != '\0')
			{
				i++;
				j = 0;
				break ;
			}
		}
	}
	return (NULL);
}
