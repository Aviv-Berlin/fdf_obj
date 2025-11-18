/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:15:08 by akosloff          #+#    #+#             */
/*   Updated: 2024/12/04 12:15:16 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_from_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = find_line(buffer[fd]);
	buffer[fd] = clean_buffer(buffer[fd], line);
	if (line == NULL)
		free(buffer[fd]);
	return (line);
}

char	*read_from_file(int fd, char *buffer)
{
	char	*string;
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		string = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (string == NULL)
			return (NULL);
		bytes_read = read(fd, string, BUFFER_SIZE);
		if (bytes_read < 0)
			return (null_free(string, buffer));
		string[bytes_read] = '\0';
		temp = get_strjoin(buffer, string);
		if (temp == NULL)
			return (null_free(string, NULL));
		null_free(string, buffer);
		buffer = temp;
	}
	return (buffer);
}

char	*null_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*clean_buffer(char *buffer, char *line)
{
	char	*temp;

	if (get_strlen(buffer) == get_strlen(line))
	{
		free (buffer);
		return (NULL);
	}
	temp = get_substr(buffer, get_strlen(line), 
			get_strlen(buffer) - get_strlen(line));
	free (buffer);
	return (temp);
}

char	*find_line(char *buffer)
{
	size_t	index;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (get_substr(buffer, 0, index + 1));
		index++;
	}
	if (buffer[index] == '\0')
		return (get_substr(buffer, 0, index +1));
	return (NULL);
}
