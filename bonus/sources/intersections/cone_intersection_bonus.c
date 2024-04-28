/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:30:52 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	check_base(t_cone *co, t_vec3 cap, t_hit *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vector_magnitude(vector_sub(point, cap));
	len -= EPSILON;
	if (len >= 0 && len <= co->radius && t > EPSILON && t < inter->t)
	{
		inter->a = co->normal;
		inter->t = t;
		inter->m = co->height;
		return (true);
	}
	return (false);
}

bool	check_sides(t_cone *cone, t_hit *inter, double t)
{
	t_vec3	oc;
	t_vec3	tmp;
	t_vec3	point;
	double	angle;
	double	m;

	point = ray_at(&inter->ray, t);
	oc = vector_sub(inter->ray.origin, cone->tip);
	m = vector_dot(inter->ray.direction, cone->normal) * t + vector_dot(oc,
			cone->normal);
	tmp = vector_sub(point, cone->tip);
	angle = acos(vector_cossine(cone->normal, tmp)) - EPSILON;
	if (m >= 0 && m <= cone->height && angle - EPSILON <= cone->angle
		&& t > EPSILON && t < inter->t)
	{
		inter->a = vector_add(cone->tip, vector_scale(cone->normal, m));
		inter->m = m;
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersect(t_cone *cone, t_ray *ray, t_vec3 cap)
{
	t_plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, cone->normal, cone->color);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersects(t_cone *cone, t_equation *equation, t_hit *inter)
{
	double	t3;

	if (!solve(equation))
		return (0);
	inter->t = INFINITY;
	t3 = cap_intersect(cone, &inter->ray, cone->base);
	check_sides(cone, inter, equation->t1);
	check_sides(cone, inter, equation->t2);
	check_base(cone, cone->base, inter, t3);
	if (inter->t == INFINITY || inter->t < 0)
		return (0);
	return (inter->t);
}

bool	cone_intersect(t_cone *cone, t_ray *ray, t_hit *inter)
{
	t_vec3		oc;
	t_equation	eq;
	double		t;

	inter->t = -1.0f;
	eq = (t_equation){0, 0, 0, 0, 0};
	oc = vector_sub(ray->origin, cone->tip);
	eq.a = pow(vector_dot(ray->direction, cone->normal), 2)
		- pow(cos(cone->angle), 2);
	eq.b = 2.0f * (vector_dot(ray->direction, cone->normal) * vector_dot(oc,
				cone->normal) - vector_dot(ray->direction, oc)
			* pow(cos(cone->angle), 2));
	eq.c = pow(vector_dot(oc, cone->normal), 2) - vector_dot(oc, oc)
		* pow(cos(cone->angle), 2);
	inter->ray = *ray;
	t = verify_intersects(cone, &eq, inter);
	if (t > 0.0f)
	{
		inter->t = t;
		inter->color = cone->color;
		return (true);
	}
	return (false);
}
