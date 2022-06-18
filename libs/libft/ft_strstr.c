/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:48:50 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/28 14:09:45 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return (0);
	i = 0;
	j = 0;
	while (big[i] != '\0')
	{
		while (big[i] != little[j] && big[i] != '\0')
			i++;
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (1);
			if (big[i + j] != little[j] && little[j] != '\0')
			{
				i++;
				j = 0;
				break ;
			}
		}
	}
	return (0);
}
