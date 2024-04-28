/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_02_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:20:42 by muhcelik          #+#    #+#             */
/*   Updated: 2024/02/18 13:19:40 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	ambient_print(t_light *s)
{
	printf("Ambient:\n");
	printf("  Ratio: (%.02f)\n", s->ratio);
	printf("  t_color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}
