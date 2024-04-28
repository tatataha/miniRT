/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:08:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	cylinder_from_strings(t_cylinder *cy, char **tokens)
{
	char		**coords;
	char		**n;
	char		**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[5], ',');
	cy->radius = ft_atod(tokens[3]) / 2.0;
	cy->center = vector_from_string(coords);
	cy->height = ft_atod(tokens[4]);
	cy->color = color_from_strings(cl);
	cy->normal = vector_from_string(n);
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);
	if (vector_magnitude(cy->normal) < 1.0 - EPSILON \
		|| cy->radius < EPSILON || cy->height < EPSILON)
		return (false);
	cy->normal = vector_normalize(cy->normal);
	cy->cap_base = vector_add(cy->center, vector_scale(cy->normal, \
	-cy->height / 2.0));
	cy->cap_top = vector_add(cy->center, vector_scale(cy->normal, \
	cy->height / 2.0));
	return (true);
}
