/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:11:06 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_from_strings(t_plane *pl, char **tokens)
{
	char	**coords;
	char	**n;
	char	**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[3], ',');
	pl->center = vector_from_string(coords);
	pl->normal = vector_from_string(n);
	pl->color = color_from_strings(cl);
	if (vector_magnitude(pl->normal) < 1.0 - EPSILON)
		return (false);
	pl->normal = vector_normalize(pl->normal);
	pl->normal = vector_add(pl->normal, (t_vec3){EPSILON, EPSILON, EPSILON});
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);
	return (true);
}

t_plane	plane_from_numbers(t_vec3 center, t_vec3 normal, t_color color)
{
	t_plane	plane;

	plane = (t_plane){.center = center, .normal = normal, .color = color};
	return (plane);
}
