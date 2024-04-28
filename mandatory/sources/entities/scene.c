/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:05 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/entities.h"

t_scene	*scene_create(void)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->shapes = ft_vector_new((void *)&shape_copy, &free, \
	(void *)&shape_print);
	scene->lights = ft_vector_new((void *)&light_copy, &free, \
	(void *)&light_print);
	return (scene);
}

void	scene_destroy(t_scene **scene)
{
	if (!(*scene))
		return ;
	ft_vector_delete((*scene)->shapes);
	ft_vector_delete((*scene)->lights);
	ft_matrix_delete((*scene)->map, &free);
	if ((*scene)->disp.img)
		mlx_destroy_image((*scene)->disp.mlx, (*scene)->disp.img);
	if ((*scene)->disp.win)
		mlx_destroy_window((*scene)->disp.mlx, (*scene)->disp.win);
	free(*scene);
	*scene = NULL;
}
