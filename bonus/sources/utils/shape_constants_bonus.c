/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constants_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:15:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	compute_shapes_constants(t_vector *shapes)
{
	t_shape		*shape;
	t_cylinder	*cy;
	t_cone		*cone;
	uint32_t	i;

	i = -1;
	while (++i < shapes->size)
	{
		shape = ft_vector_at(shapes, i);
		if (shape->type == CYLINDER)
		{
			cy = &shape->data.cy;
			cy->cap_base = vector_add(cy->center, vector_scale(cy->normal,
						-cy->height / 2.0));
			cy->cap_top = vector_add(cy->center, vector_scale(cy->normal,
						cy->height / 2.0));
		}
		else if (shape->type == CONE)
		{
			cone = &shape->data.cn;
			cone->angle = atan(cone->radius / cone->height) + EPSILON;
			cone->base = vector_add(cone->tip, vector_scale(cone->normal,
						cone->height));
		}
	}
}
