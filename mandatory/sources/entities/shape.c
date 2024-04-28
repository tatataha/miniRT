/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:55:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:20:28 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shape_copy(t_shape *shape)
{
	t_shape	*copy;

	copy = ft_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
	copy->id = shape->id;
	copy->type = shape->type;
	if (shape->type == SPHERE)
		copy->data.sp = shape->data.sp;
	else if (shape->type == PLANE)
		copy->data.pl = shape->data.pl;
	else if (shape->type == CYLINDER)
		copy->data.cy = shape->data.cy;
	return (copy);
}

t_shape	*shape_new(void	*data, t_shape_type type, int id)
{
	t_shape	*shape;

	shape = ft_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->id = id;
	shape->type = type;
	if (type == SPHERE)
		shape->data.sp = *(t_sphere *)data;
	else if (type == PLANE)
		shape->data.pl = *(t_plane *)data;
	else if (type == CYLINDER)
		shape->data.cy = *(t_cylinder *)data;
	return (shape);
}
