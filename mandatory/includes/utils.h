/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:14:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:21:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

/**
 * @brief this function checks how many intersections the ray has with the
 * object.
 *
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	determinant(t_equation *eq);

/**
 * @brief this function will solve the quadratic equation, store the results
 * inside the t_equation struct (t1 and t2 variables) and return the number
 * of intersections the ray has with the object.
 *
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	solve(t_equation *eq);

/**
 * @brief funtion that prints the given error message as parameter and exits
 * the program destroying the world struct (freeing all the memory
 * previously allocated)
 *
 * @param scene t_scene struct with all the information of the world
 * @param text text to be printed
 */
void	message(t_scene *scene, char *text);

void	error_returner(char *type, char *txt, int n);
void	error(char *message);
double	radians(double deg);

/**
 * @brief Returns the maximum between a and b
 * @param double a
 * @param double b
*/
double	max(double a, double b);

/**
 * @brief Returns the minimum between a and b
 * @param double a
 * @param double b
*/
double	min(double a, double b);

#endif
