/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:33:57 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 14:51:17 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*safe_check_and_initialize(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > RLIMIT_NOFILE)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*add_to_temp(char *s1, char *s2)
{
	char	*new_str;
	size_t	counter[2];

	if (!s1 && !s2)
		return (NULL);
	new_str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	counter[0] = 0;
	counter[1] = 0;
	while (s1 && s1[counter[0]] != '\0')
	{
		new_str[counter[0]] = s1[counter[0]];
		counter[0]++;
	}
	while (s2 && s2[counter[1]] != '\0')
	{
		new_str[counter[0]] = s2[counter[1]];
		counter[0]++;
		counter[1]++;
	}
	new_str[counter[0]] = '\0';
	free(s1);
	return (new_str);
}

static char	*create_line(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	new_str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*trim_temp(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = ft_calloc(ft_strlen(str) - i, sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

int	get_next_line(int fd, char **line)
{
	static char	*temp;
	char		*buffer;
	ssize_t		size;

	buffer = safe_check_and_initialize(fd, line);
	if (!buffer)
		return (-1);
	size = 1;
	while (size > 0 && !ft_strhaschr(temp, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[size] = '\0';
		temp = add_to_temp(temp, buffer);
	}
	free(buffer);
	*line = create_line(temp);
	temp = trim_temp(temp);
	if (size == 0)
		return (0);
	return (1);
}
