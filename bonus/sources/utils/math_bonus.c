/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:33:34 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 12:28:19 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	determinant(t_equation *eq)
{
	double	delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (-1);
	return (delta);
}

double	solve(t_equation *eq)
{
	double	delta;

	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->t1 = -eq->c / eq->b;
		return (0);
	}
	delta = determinant(eq);
	if (delta < 0)
		return (-1);
	eq->t1 = (-eq->b - sqrt(delta)) / (2 * eq->a);
	eq->t2 = (-eq->b + sqrt(delta)) / (2 * eq->a);
	return (delta);
}

double	radians(double deg)
{
	return ((deg * PI) / 180.0f);
}

double	max(double a, double b)
{
	return ((a) * (a > b) + (b) * (b > a));
}

double	min(double a, double b)
{
	return ((a) * (a < b) + (b) * (b < a));
}
