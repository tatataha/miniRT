/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:50:54 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3])
{
	char	**color;

	if (ft_matrix_size(tokens) != 3)
		return (error("Wrong number of args in ambient (need 3)"), false);
	if (!parse_syntax(tokens, "001"))
		return (error("Misconfiguration in commas/numbers in ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (error("Colors misformatting in ambient"), false);
	if (ft_atod(tokens[1]) < 0.0 || ft_atod(tokens[1]) > 1.0)
		return (error("Ambient ratio out of bounds [0,1.0]"), false);
	color = ft_split(tokens[2], ',');
	ambient->ratio = ft_atod(tokens[1]);
	ambient->color = color_from_strings(color);
	ft_matrix_delete(color, &free);
	counters[0]++;
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int counters[3])
{
	char	**color;
	char	**normal;

	if (ft_matrix_size(tokens) != 4)
		return (error("Wrong number of args in camera (need 4)"), false);
	if (!parse_syntax(tokens, "0110"))
		return (error("Misconfiguration in commas/numbers in camera"), false);
	color = ft_split(tokens[1], ',');
	normal = ft_split(tokens[2], ',');
	cam->center = vector_from_string(color);
	cam->normal = vector_from_string(normal);
	cam->normal = vector_add(cam->normal, (t_vec3){0.0001, 0.0001, 0.0001});
	ft_matrix_delete(color, &free);
	ft_matrix_delete(normal, &free);
	if (vector_magnitude(cam->normal) < 1.0 - EPSILON)
		return (error("Normal vector is too small in camera"), false);
	cam->normal = vector_normalize(cam->normal);
	cam->fov = ft_atod(tokens[3]);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (error("FOV out of bounds [0, 180]"), false);
	counters[1]++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3])
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (ft_matrix_size(tokens) != 4)
		return (error("Wrong number of args in light (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (error("Misconfiguration in commas/numbers in light"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in light"), false);
	if (ft_atod(tokens[2]) < 0.0 || ft_atod(tokens[2]) > 1.0)
		return (error("t_light brightness out of bounds [0,1.0]"), false);
	origin = ft_split(tokens[1], ',');
	color = ft_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	ft_vector_push(lights, light);
	ft_matrix_delete(origin, &free);
	ft_matrix_delete(color, &free);
	counters[2]++;
	return (true);
}
