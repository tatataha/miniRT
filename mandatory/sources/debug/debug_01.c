/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:35:07 by muhcelik          #+#    #+#             */
/*   Updated: 2024/02/18 13:19:40 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_print(t_camera *c)
{
	printf("t_camera:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: %.4lf, %.4lf, %.4lf\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
}

void	light_print(t_light *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.4lf, %.4lf, %.4lf)\n", \
		l->center.x, l->center.y, l->center.z);
	printf("  Ratio: %.4lf\n", l->ratio);
	printf("  t_color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}

void	color_print(t_color *color)
{
	printf("#%02X%02X%02X\n", color->r, color->g, color->b);
}

void	vector_print(t_vec3 vec)
{
	printf("Vec: (x, y, z) = (%.4lf, %.4lf, %.4lf)\n", vec.x, vec.y, vec.z);
}

void	shape_print(t_shape *shape)
{
	if (shape->type == SPHERE)
		sphere_print(&shape->data.sp);
	printf("  ID: %d\n", shape->id);
}
