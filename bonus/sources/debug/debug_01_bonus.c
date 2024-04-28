/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:20:03 by muhcelik          #+#    #+#             */
/*   Updated: 2024/02/18 13:19:57 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	camera_print(t_camera *c)
{
	printf("t_camera:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", c->center.x, c->center.y,
		c->center.z);
	printf("  Normal: %.4lf, %.4lf, %.4lf\n", c->normal.x, c->normal.y,
		c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
}

void	light_print(t_light *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.4lf, %.4lf, %.4lf)\n", l->center.x, l->center.y,
		l->center.z);
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

void	sphere_print(t_sphere *s)
{
	printf("t_sphere:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", s->center.x, s->center.y,
		s->center.z);
	printf("  Radius: %.4lf\n", s->radius);
	printf("  t_color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}
