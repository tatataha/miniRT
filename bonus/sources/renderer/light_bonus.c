/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:39 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:36:44 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_color	ambient(t_color color, double ratio)
{
	return (color_mult(color, ratio));
}

bool	is_shadowed(t_scene *scene, t_light *bulb, t_hit *closest)
{
	t_vec3		light_dir;
	t_ray		ray;
	double		light_distance;

	light_dir = vector_sub(bulb->center, closest->point);
	light_distance = vector_magnitude(light_dir);
	ray.origin = vector_add(closest->point, (t_vec3){0.0001, 0.0001, 0.0001});
	ray.direction = vector_normalize(light_dir);
	return (is_obscured(scene->shapes, closest->shape, &ray, light_distance));
}

bool	is_obscured(t_vector *shapes, t_shape *self, t_ray *ray, double max_t)
{
	uint32_t	i;
	t_hit		tmp;
	t_shape		*shape;

	i = -1;
	tmp.t = INFINITY;
	tmp.shape = NULL;
	while (++i < shapes->size)
	{
		shape = ft_vector_at(shapes, i);
		if (shape->id == self->id)
			continue ;
		if (intersects(shape, ray, &tmp) && tmp.t < max_t)
			return (true);
	}
	return (false);
}

t_color	diffuse(t_light *bulb, t_hit *inter, double i)
{
	t_vec3	light_dir;
	t_color	diff_color;
	double	cos_angle;
	double	diffuse_ratio;
	double	attenuation;

	light_dir = vector_sub(bulb->center, inter->point);
	attenuation = min(1.0, 90.0 / vector_magnitude(light_dir));
	cos_angle = vector_cossine(inter->normal, light_dir);
	diffuse_ratio = max(0.0, i * cos_angle * attenuation);
	diff_color = color_mult(inter->color, diffuse_ratio);
	diff_color = color_blender(diff_color, bulb->color);
	return (diff_color);
}

t_color	specular(t_light *bulb, t_hit *closest)
{
	double	spec_ratio;
	t_vec3	light_dir;
	t_vec3	camera_dir;
	t_vec3	half_vector;
	double	cosine;

	if (closest->shape->shininess < 1.0)
		return ((t_color){0, 0, 0, 0});
	light_dir = vector_sub(bulb->center, closest->point);
	camera_dir = vector_scale(closest->ray.direction, -1);
	camera_dir = vector_normalize(camera_dir);
	half_vector = vector_normalize(vector_add(camera_dir, light_dir));
	cosine = max(0.0, vector_dot(half_vector, closest->normal));
	spec_ratio = closest->shape->sp_ratio * bulb->ratio * pow(cosine,
			closest->shape->shininess);
	return (color_blender(color_mult(closest->color, spec_ratio), bulb->color));
}
