/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightsource.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:49:13 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	*light_new(char **c, char *ratio, char **cl)
{
	t_light	*bulb;

	bulb = ft_calloc(1, sizeof(t_light));
	if (!bulb)
		return (NULL);
	bulb->center = vector_from_string(c);
	bulb->ratio = ft_atod(ratio);
	bulb->color = color_from_strings(cl);
	return (bulb);
}

t_light	*light_copy(t_light *bulb)
{
	t_light	*copy;

	copy = ft_calloc(1, sizeof(t_light));
	if (!copy)
		return (NULL);
	*copy = *bulb;
	return (copy);
}
