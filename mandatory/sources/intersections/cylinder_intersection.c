/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:33:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_caps(t_cylinder *cy, t_vec3 cap, t_hit *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vector_magnitude(vector_sub(point, cap));
	len += EPSILON;
	if (len <= cy->radius && t > EPSILON && t < inter->t)
	{
		inter->a = cap;
		inter->t = t;
		return (true);
	}
	return (false);
}

bool	check_walls(t_cylinder *cy, t_hit *inter, double t)
{
	t_vec3	point;
	t_vec3	co;
	t_vec3	a;
	double	m;
	double	len;

	point = ray_at(&inter->ray, t);
	co = vector_sub(inter->ray.origin, cy->cap_base);
	m = vector_dot(inter->ray.direction, cy->normal) * t + \
		vector_dot(co, cy->normal);
	a = vector_add(cy->cap_base, vector_scale(cy->normal, m));
	len = vector_magnitude(vector_sub(point, a));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy->height && len <= cy->radius \
		&& t > EPSILON && t < inter->t)
	{
		inter->a = a;
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersection(t_cylinder *cy, t_ray *ray, t_vec3 cap)
{
	t_plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, cy->normal, (t_color){0, 0, 0, 0});
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersections(t_cylinder *cy, t_ray *ray, \
	t_equation *eq, t_hit *hit_info)
{
	double	t3;
	double	t4;

	t3 = cap_intersection(cy, ray, cy->cap_base);
	t4 = cap_intersection(cy, ray, cy->cap_top);
	hit_info->t = INFINITY;
	hit_info->ray = *ray;
	check_walls(cy, hit_info, eq->t1);
	check_walls(cy, hit_info, eq->t2);
	check_caps(cy, cy->cap_base, hit_info, t3);
	check_caps(cy, cy->cap_top, hit_info, t4);
	if (hit_info->t == INFINITY)
		return (0);
	return (hit_info->t);
}

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray, t_hit *hit_info)
{
	double		t;
	t_vec3		cy_to_ray;
	t_equation	eq;

	eq.t1 = -1;
	eq.t2 = -1;
	cy_to_ray = vector_sub(ray->origin, cy->cap_base);
	eq.a = vector_dot(ray->direction, ray->direction) - \
		pow(vector_dot(ray->direction, cy->normal), 2);
	eq.b = 2 * (vector_dot(ray->direction, cy_to_ray) - \
		(vector_dot(ray->direction, cy->normal) * \
		vector_dot(cy_to_ray, cy->normal)));
	eq.c = vector_dot(cy_to_ray, cy_to_ray) - \
		pow(vector_dot(cy_to_ray, cy->normal), 2) - pow(cy->radius, 2);
	solve(&eq);
	if (eq.t1 <= 0 && eq.t2 <= 0)
		return (false);
	t = verify_intersections(cy, ray, &eq, hit_info);
	if (t > 0.0f)
	{
		hit_info->t = t;
		hit_info->color = cy->color;
		return (true);
	}
	return (false);
}
