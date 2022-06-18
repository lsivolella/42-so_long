/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:12:58 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/05/24 09:33:32 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	size1;
	unsigned int	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	newstr = malloc((size1 + size2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (*s1)
		*(newstr++) = *(s1++);
	while (*s2)
		*(newstr++) = *(s2++);
	*newstr = '\0';
	return (newstr - (size1 + size2));
}
