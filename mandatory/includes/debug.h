/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:46:12 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:21:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "miniRT.h"

/**
 * @brief Prints in the standard output all the values that represent the
 * ambient light in the scene.
 *
 * @param s The t_light struct (representing ambient light) to debug
 */
void	ambient_print(t_light *s);

/**
 * @brief Prints in the standard output all the values related to the
 * scene's camera.
 *
 * @param s The t_camera struct to debug
 */
void	camera_print(t_camera *s);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * light source.
 *
 * @param l The t_light struct (representing a light source) to debug
 */
void	light_print(t_light *l);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * sphere.
 *
 * @param s The t_sphere struct to debug
 */
void	sphere_print(t_sphere *s);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * plane.
 *
 * @param p The plane struct to work with to debug
 */
void	plane_print(t_plane *p);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * cylinder.
 *
 * @param c The t_cylinder struct to work with to debug
 */
void	cylinder_print(t_cylinder *c);

/**
 * @brief Redirects the program flow to one of the other print functions,
 * since shape represents all the possible shapes. It also prints a shapes's
 * ID.
 *
 * @param shape The t_shape struct to debug
 */
void	shape_print(t_shape *shape);

/**
 * @brief Prints in the standard output all the values related to a color.
 *
 * @param color The t_color struct to debug
 */
void	color_print(t_color *color);

/**
 * @brief Prints in the standard output all the values related to a 3D vector.
 *
 * @param vec The t_vec3 struct to debug
 */
void	vector_print(t_vec3 vec);

/**
 * @brief Prints in the standard output all the values related to the world.
 * This includes most of the other print functions, since t_scene is the main
 * struct.
 *
 * @param world A pointer to the t_scene struct
 */
void	scene_print(t_scene *scene);

#endif
