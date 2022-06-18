/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:57:10 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/08 17:52:15 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_string(unsigned int start, size_t size_s, size_t len)
{
	char	*str;
	size_t	last_index;

	if (start > size_s)
		last_index = 0;
	else if (size_s - start < len)
		last_index = size_s - start;
	else
		last_index = len;
	str = ft_calloc(last_index + 1, sizeof(char));
	if (str)
		str[last_index] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	dest = ft_create_string(start, size_s, len);
	if (!dest)
		return (NULL);
	i = 0;
	if (start <= size_s)
	{
		while (i < len && s[start + i])
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
