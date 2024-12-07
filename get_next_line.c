/* ************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egokce <eecegokcece@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:30:54 by egokce            #+#    #+#             */
/*   Updated: 2024/12/06 20:23:52 by egokce           ###   ########.fr       */
/*                                                                            */
/* ************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

ssize_t	read_byte(int fd, char *buffer)
{
	ssize_t	byte;
    size_t  i;

    i = 0;
	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte > 0)
	{
		buffer[byte] = '\0';
	}
    else if (byte == 0)
        buffer[0] = '\0';
	return (byte);
}

/*char	control(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return ('y');	
		i++;
	}
	return ('n');
}*/

char	**ft_split_line(char *line)
{
	size_t	i;
    size_t  j;
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
			break;	
		}
        i++;
	}
	result[0] = ft_substr(line, 0, i);
    result[1] = ft_substr(line, i , (j - i + 1));
    return (result);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char	**str;
	char	*tmp;
	char	buffer[BUFFER_SIZE];
	ssize_t	byte;

	while (1)
	{
		byte = read_byte(fd, buffer);
		if (byte == 0 && (!line))
			return (NULL);
		if (byte == -1)
			return (NULL);
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			str = ft_split_line(line);
			line = str[1];
			return (str[0]);
		}
		else if (byte == 0 && !ft_strchr(line, '\n'))
            return (free(str[0]),free(str[1]), free(str),line);
	}
}


int main()
{
	int fd = open("ece.txt", O_RDONLY);
	char *line;
	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
}