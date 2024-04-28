/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:25:52 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	sphere_intersect(t_sphere *sp, t_ray *ray, t_hit *hit_info)
{
	t_vec3		sphere_to_ray;
	t_equation	eq;

	eq.t1 = -1.0f;
	sphere_to_ray = vector_sub(ray->origin, sp->center);
	eq.a = vector_dot(ray->direction, ray->direction);
	eq.b = 2.0f * vector_dot(sphere_to_ray, ray->direction);
	eq.c = vector_dot(sphere_to_ray, sphere_to_ray) - pow(sp->radius, 2);
	if (solve(&eq) > 0 && (eq.t1 > EPSILON || eq.t2 > EPSILON))
	{
		if (eq.t1 > EPSILON)
			hit_info->t = eq.t1;
		else
			hit_info->t = eq.t2;
		hit_info->color = sp->color;
		return (true);
	}
	return (false);
}
