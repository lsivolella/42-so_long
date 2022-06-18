/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:32:35 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/07 12:53:51 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*alts;

	alts = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (alts + i);
	while (i != 0)
	{
		if (alts[i] == (char)c)
			return (alts + i);
		i--;
	}
	if (s[0] == (char)c)
		return (alts);
	return (0);
}
