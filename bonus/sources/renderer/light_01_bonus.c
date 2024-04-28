/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_01_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:26:16 by muhcelik          #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	illuminate(t_scene *scene, t_hit *closest)
{
	uint32_t	i;
	t_color		color;
	t_light		*bulb;

	i = -1;
	color = ambient(closest->color, scene->ambient.ratio);
	while (++i < scene->lights->size)
	{
		bulb = ft_vector_at(scene->lights, i);
		if (is_shadowed(scene, bulb, closest))
			continue ;
		color = color_add(color, diffuse(bulb, closest, bulb->ratio));
		color = color_add(color, specular(bulb, closest));
	}
	closest->color = color;
}
