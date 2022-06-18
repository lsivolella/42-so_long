/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:04:37 by lgoncalv          #+#    #+#             */
/*   Updated: 2021/06/02 14:19:07 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && !trigger)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static char	*ft_copy_word(const char *str, int start, int end)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_split_s(const char *src, char **dest, char c, size_t words)
{
	size_t	start;
	size_t	end;
	size_t	counter;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (src[end] != '\0' && words > 0)
	{
		counter = 0;
		while (src[end] != c && src[end] != '\0')
			counter = ++end;
		if ((src[end] == c || src[end] == '\0') && counter > 0)
		{
			dest[i++] = ft_copy_word(src, start, end);
			if (src[end] == '\0')
				break ;
			start = ++end;
		}
		else if (src[end] == c && counter == 0)
			start = ++end;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_split_s(s, str, c, words);
	return (str);
}
