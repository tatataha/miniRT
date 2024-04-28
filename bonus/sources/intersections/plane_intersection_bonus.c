/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:26:41 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_intersect(t_plane *pl, t_ray *ray, t_hit *hit_info)
{
	t_vec3		plane_to_ray;
	t_equation	equation;

	if (vector_dot(ray->direction, pl->normal) != 0.0)
	{
		plane_to_ray = vector_sub(ray->origin, pl->center);
		equation.a = 0;
		equation.b = vector_dot(ray->direction, pl->normal);
		equation.c = vector_dot(plane_to_ray, pl->normal);
		solve(&equation);
		if (equation.t1 > EPSILON)
		{
			hit_info->t = equation.t1;
			hit_info->color = pl->color;
			return (true);
		}
	}
	return (false);
}
