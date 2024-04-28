/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:59:53 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	cone_from_strings(t_cone *cone, char **tokens)
{
	char	**coords;
	char	**n;
	char	**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[5], ',');
	*cone = (t_cone){
		.radius = ft_atod(tokens[3]),
		.height = ft_atod(tokens[4]),
		.tip = vector_from_string(coords),
		.normal = vector_from_string(n),
		.color = color_from_strings(cl),
	};
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);
	if (vector_magnitude(cone->normal) < 1.0 - EPSILON || cone->radius < EPSILON
		|| cone->height < EPSILON)
		return (false);
	cone->normal = vector_normalize(cone->normal);
	return (true);
}
