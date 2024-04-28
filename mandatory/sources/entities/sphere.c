/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:21:07 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	sphere_from_strings(t_sphere *sp, char **tokens)
{
	char		**coords;
	char		**cl;

	coords = ft_split(tokens[1], ',');
	cl = ft_split(tokens[3], ',');
	sp->center = vector_from_string(coords);
	sp->color = color_from_strings(cl);
	sp->radius = ft_atod(tokens[2]) / 2.0;
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(cl, &free);
	if (sp->radius < EPSILON)
		return (false);
	return (true);
}
