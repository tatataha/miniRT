/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:39 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:24:17 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	illuminate(t_scene *scene, t_hit *closest)
{
	t_color	color;
	t_light	*bulb;

	bulb = ft_vector_at(scene->lights, 0);
	color = ambient(closest->color, scene->ambient.ratio);
	if (bulb && !is_shadowed(scene, closest))
		color = color_add(color, diffuse(bulb, closest, bulb->ratio));
	closest->color = color;
}

t_color	ambient(t_color	color, double ratio)
{
	return (color_mult(color, ratio));
}

bool	is_shadowed(t_scene *scene, t_hit *closest)
{
	t_vec3		light_dir;
	t_light		*light;
	t_ray		ray;
	double		light_distance;

	if (!scene->lights->size)
		return (false);
	light = ft_vector_at(scene->lights, 0);
	light_dir = vector_sub(light->center, closest->point);
	light_distance = vector_magnitude(light_dir);
	ray.origin = vector_add(closest->point, \
	(t_vec3){0.0001, 0.0001, 0.0001});
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
	diffuse_ratio = i * cos_angle * attenuation;
	diff_color = color_mult(inter->color, diffuse_ratio);
	return (diff_color);
}
