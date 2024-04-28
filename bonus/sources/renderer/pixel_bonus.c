/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:06:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:21:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/renderer.h"

void	put_pixel(t_scene *w, t_color c, int x, int y)
{
	char	*dst;

	dst = w->disp.addr + (y * WIDTH + x) * (w->disp.bpp / 8);
	*(unsigned int *)dst = (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
}
