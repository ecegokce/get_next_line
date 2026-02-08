/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egokce <eecegokcece@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:38:27 by egokce            #+#    #+#             */
/*   Updated: 2024/12/16 22:10:58 by egokce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

ssize_t	read_byte(int fd, char *buffer)
{
	ssize_t	byte;

	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte > 0)
		buffer[byte] = '\0';
	else if (byte == 0)
		buffer[0] = '\0';
	return (byte);
}

char	**ft_split_line(char *line)
{
	size_t	i;
	size_t	j;
	char	**result;

	result = malloc(2 * sizeof(char *));
	if (!result)
		return (NULL);
	j = ft_strlen(line);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[0] = ft_substr(line, 0, i);
	result[1] = ft_substr(line, i, (j - i + 1));
	return (result);
}

char	*ft_newline(char **line, char *buffer)
{
	char	**str;
	char	*tmp;

	*line = ft_strjoin(*line, buffer);
	if (ft_strchr(*line, '\n'))
	{
		str = ft_split_line(*line);
		if (str[0] == NULL || str[1] == NULL)
		{
			free(str[0]);
			free(str[1]);
			free(str);
			return (NULL);
		}
		free(*line);
		*line = NULL;
		*line = str[1];
		tmp = str[0];
		free(str);
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		byte;
	char		*tmp;

	while (1)
	{
		byte = read_byte(fd, buffer);
		if ((byte == 0 && (line == NULL || *line == '\0')) || byte < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		tmp = ft_newline(&line, buffer);
		if (tmp != NULL)
			return (tmp);
		else if (byte == 0 && ft_strchr(line, '\n') == NULL)
		{
			tmp = ft_strdup(line);
			free(line);
			line = NULL;
			return (tmp);
		}
	}
}
