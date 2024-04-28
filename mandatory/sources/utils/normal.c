/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	sphere_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vector_sub(point, inter->shape->data.sp.center);
	return (normal);
}

t_vec3	shape_normal(t_hit *inter, t_ray *ray)
{
	if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else
		return (sphere_normal(inter, ray));
}

t_vec3	cylinder_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vector_sub(point, inter->a);
	if (vector_compare(inter->a, inter->shape->data.cy.cap_base))
		normal = vector_scale(inter->shape->data.cy.normal, -1);
	else if (vector_compare(inter->a, inter->shape->data.cy.cap_top))
		normal = inter->shape->data.cy.normal;
	return (normal);
}
