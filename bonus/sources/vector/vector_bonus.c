/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec3	vector_create(double x, double y, double z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

double	vector_magnitude(t_vec3 self)
{
	return (sqrt(vector_dot(self, self)));
}
