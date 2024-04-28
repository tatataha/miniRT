/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:23 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "miniRT.h"

t_color	color_create(int r, int g, int b);

t_color	color_add(t_color c1, t_color c2);
t_color	color_mult(t_color color, double k);
t_color	color_from_strings(char **rgb);

#endif
