/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:31 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec3	vector_normalize(t_vec3 vec)
{
	return (vector_scale(vec, 1.0 / vector_magnitude(vec)));
}

t_vec3	vector_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

t_vec3	vector_from_string(char **vec)
{
	t_vec3	vector;

	vector.x = ft_atod(vec[X]);
	vector.y = ft_atod(vec[Y]);
	vector.z = ft_atod(vec[Z]);
	return (vector);
}

double	vector_cossine(t_vec3 v1, t_vec3 v2)
{
	double	dot;
	double	lengths;

	dot = vector_dot(v1, v2);
	lengths = vector_magnitude(v1) * vector_magnitude(v2);
	return (dot / lengths);
}

bool	vector_compare(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}
