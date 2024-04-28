/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:10 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:18:59 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_hit *hit_info)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, hit_info));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, hit_info));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, hit_info));
	return (false);
}
