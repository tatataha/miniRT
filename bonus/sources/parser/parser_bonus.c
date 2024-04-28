/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:57:18 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	parse_entity(t_scene *scene, char **tokens, int counters[2])
{
	if (!(ft_strcmp("A", tokens[0])))
		return (parse_ambient_light(&scene->ambient, tokens, &counters[0]));
	else if (!(ft_strcmp("C", tokens[0])))
		return (parse_camera(&scene->camera, tokens, &counters[1]));
	else if (!(ft_strcmp("l", tokens[0])))
		return (parse_light_source(scene->lights, tokens));
	else if (!(ft_strcmp("sp", tokens[0])))
		return (parse_sphere(scene->shapes, tokens));
	else if (!(ft_strcmp("pl", tokens[0])))
		return (parse_plane(scene->shapes, tokens));
	else if (!(ft_strcmp("cy", tokens[0])))
		return (parse_cylinder(scene->shapes, tokens));
	else if (!ft_strcmp(tokens[0], "cn"))
		return (parse_cone(scene->shapes, tokens));
	else
		return (error("Error parsing entities"), false);
	return (true);
}

void	parse_map(t_scene *scene, char **map, int counters[2])
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	while (map[++i])
	{
		tokens = ft_split(map[i], ' ');
		ok = parse_entity(scene, tokens, counters);
		ft_matrix_delete(tokens, &free);
		if (!ok)
			message(scene, ERROR_SYNTAX);
	}
}

t_scene	*parse(char *filename)
{
	t_scene	*scene;
	int		counters[2];

	ft_bzero(counters, 2 * sizeof(int));
	if (!(is_filename_valid(filename)))
		message(NULL, ERROR_NOT_RT);
	scene = scene_create();
	if (!scene)
		message(NULL, ERROR_MALLOC);
	scene->map = read_map(scene, filename);
	if (ft_matrix_size(scene->map) == 0)
		message(NULL, ERROR_EMPTY_MAP);
	parse_map(scene, scene->map, counters);
	if (counters[1] == 0)
		message(scene, ERROR_NO_CAMERA);
	if (counters[0] > 1 || counters[1] > 1)
		message(scene, ERROR_TOO_MANY);
	return (scene);
}
