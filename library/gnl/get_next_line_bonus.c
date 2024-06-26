/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:38:45 by ioztimur          #+#    #+#             */
/*   Updated: 2024/02/18 13:30:37 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_left(int fd, char *left_str)
{
	int		rd_bytes;
	char	*buffer;

	rd_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd_bytes != 0 && !(gnl_strchr(left_str, '\n')))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buffer);
			free(left_str);
			return (NULL);
		}
		buffer[rd_bytes] = 0;
		left_str = gnl_strjoin(left_str, buffer);
	}
	if (!left_str || !left_str[0])
		return (ft_error_check(left_str, buffer));
	free(buffer);
	return (left_str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*line;

	if (!(left_str) || !left_str[0])
		return (NULL);
	line = (char *)malloc(sizeof(char) * gnl_strlen(left_str)
			- gnl_strlen(gnl_strchr(left_str, '\n')) + 2);
	if (!line)
	{
		free(left_str);
		return (NULL);
	}
	i = 0;
	while (left_str[i] != '\n' && left_str[i])
	{
		line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left_str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str[fd] = ft_read_left(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_next_line(left_str[fd]);
	return (line);
}
