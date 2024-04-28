/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:46:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:29:15 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_viewport(t_scene *s)
{
	s->wview = tan(radians(s->camera.fov / 2.0));
	s->hview = s->wview / (4.0 / 3.0);
	s->right = vector_normalize(vector_cross(s->camera.normal, (t_vec3){0.0,
				1.0, 0.0}));
	s->up = vector_normalize(vector_cross(s->camera.normal, s->right));
	s->right = vector_normalize(vector_cross(s->camera.normal, s->up));
}

t_vec3	canvas_to_viewport(int x, int y)
{
	t_vec3	converted;
	double	width;
	double	height;

	width = WIDTH;
	height = HEIGHT;
	converted.x = ((2.0f * x) / width) - 1;
	converted.y = ((2.0f * y) / height) - 1;
	converted.z = 0;
	return (converted);
}

t_ray	cast_ray(t_scene *s, t_vec3 factors)
{
	t_ray		ray;
	t_vec3		vertical;
	t_vec3		horizontal;
	t_vec3		res;

	vertical = vector_scale(s->up, factors.y * s->hview);
	horizontal = vector_scale(s->right, factors.x * s->wview);
	res = vector_add(vertical, horizontal);
	res = vector_add(res, s->camera.normal);
	res = vector_add(res, s->camera.center);
	ray.origin = s->camera.center;
	ray.direction = vector_normalize(vector_sub(res, ray.origin));
	return (ray);
}

t_vec3	ray_at(t_ray *ray, double t)
{
	return (vector_add(ray->origin, vector_scale(ray->direction, t)));
}
