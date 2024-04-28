/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "miniRT.h"

/**
 * @brief function to create a new vector with the given values
 *
 * @param x value for x coordinate
 * @param y value for y coordinate
 * @param z value for z coordinate
 * @return vector(x, y, z)
 */
t_vec3	vector_create(double x, double y, double z);

/**
 * @brief function to calculate the length of a vector
 *
 * @param vec vector
 * @return double
 */
double	vector_magnitude(t_vec3 self);

/**
 * @brief function to normalize a vector
 *
 * @param self vector
 * @return vector(x, y, z)
 */
t_vec3	vector_normalize(t_vec3 self);

/**
 * @brief function to add two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vector_add(t_vec3 v1, const t_vec3 v2);

/**
 * @brief function to subtract two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vector_sub(t_vec3 v1, const t_vec3 v2);

/**
 * @brief function to scale a vector
 *
 * @param v1 vector to be scaled
 * @param scalar scalar value
 * @return vector(x, y, z)
 */
t_vec3	vector_scale(t_vec3 self, double scalar);

/**
 * @brief Divide each component of the vector by a scalar value
 *
 * @param vector vector
 * @param scaler scaler value
 * @return vector(x, y, z)
 */
t_vec3	vector_div(t_vec3 vector, double scalar);

/**
 * @brief function to calculate the dot product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double	vector_dot(const t_vec3 v1, const t_vec3 v2);

/**
 * @brief function to calculate the cross product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vector_cross(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to create a new vector from a string array
 *
 * @param vec string array with the values of x, y and z coordinates
 * @return vector(x, y, z)
 */
t_vec3	vector_from_string(char **vec);

/**
 * @brief function to calculate the cossine of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double	vector_cossine(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to comapre two vectors
 *
 * @param vec1 vector
 * @param vec2 vector
 * @return true if the vectors are equal, false otherwise
 */
bool	vector_compare(t_vec3 v1, t_vec3 v2);

#endif
