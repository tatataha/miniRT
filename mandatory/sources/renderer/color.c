/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:24:04 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

t_color	color_create(int r, int g, int b)
{
	t_color	color;

	color.r = ft_clamp(r, 0, 255);
	color.g = ft_clamp(g, 0, 255);
	color.b = ft_clamp(b, 0, 255);
	return (color);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	color;

	color.r = ft_clamp(c1.r + c2.r, 0, 255);
	color.g = ft_clamp(c1.g + c2.g, 0, 255);
	color.b = ft_clamp(c1.b + c2.b, 0, 255);
	return (color);
}

t_color	color_mult(t_color color, double k)
{
	return ((t_color)
		{
			.r = ft_clamp(color.r * k, 0, 255),
			.g = ft_clamp(color.g * k, 0, 255),
			.b = ft_clamp(color.b * k, 0, 255)
		}
	);
}

t_color	color_from_strings(char **rgb)
{
	t_color	color;

	color.r = ft_clamp(ft_atoi(rgb[R]), 0, 255);
	color.g = ft_clamp(ft_atoi(rgb[G]), 0, 255);
	color.b = ft_clamp(ft_atoi(rgb[B]), 0, 255);
	return (color);
}
