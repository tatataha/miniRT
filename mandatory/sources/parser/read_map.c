/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:27:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:21:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_filename_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3)
		return (false);
	return (ft_strnstr(filename + (len - 3), ".rt", len) != NULL);
}

int	get_filesize(t_scene *scene, char *filename)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(scene, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
			counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

char	**read_map(t_scene *scene, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = ft_matrix_new(get_filesize(scene, filename), 0);
	if (!map)
		message(scene, ERROR_MALLOC);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(scene, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strchr("\n#", line[0]))
			map[i++] = line;
		else
			free(line);
	}
	close(fd);
	return (map);
}
