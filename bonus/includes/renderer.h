/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:58:49 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:28:17 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief The function that renders the scene. Iterates over the scene's
 * pixels and traces a ray for each that will be used to collide with
 * the world. The pixels are painted one by one until the final image
 * is rendered.
 *
 * @param w The scene struct
 * @return int (dummy value)
 */
int		render(t_scene *s);

/**
 * @brief Puts a pixel in an image with the given color and at the given
 * coordinates
 *
 * @param w The t_world struct
 * @param c The pixel's color
 * @param x The horizontal displacement
 * @param y The vertical displacement
 */
void	put_pixel(t_scene *w, t_color c, int x, int y);

/**
 * @brief Initializes the scene's viewport (what the camera can see). The
 * viewport will be supported by 3 vectors: up, right and forward.
 * Together, those vectors can return any point on the plane.
 *
 * @param s The t_scene struct
 */
void	init_viewport(t_scene *s);

/**
 * @brief Converts a pixel in x (0 to width - 1) and y (0 to height - 1) to
 * viewport x and viewport y factors (between -1 and 1). These factors are used
 * with the viewport vectors to access any point.
 *
 * @param x The pixel's x coordinate
 * @param y The pixel's y coordinate
 * @return t_vec3 The x and y viewport factors
 */
t_vec3	canvas_to_viewport(int x, int y);

/**
 * @brief Casts an infinite ray in space from the camera with the direction
 * of one of the viewport's point.
 *
 * @param s The t_scene struct
 * @param factors The viewport factors
 * @return t_ray The casted ray
 */
t_ray	cast_ray(t_scene *s, t_vec3 factors);

/**
 * @brief Returns the point in the given ray with t direction vectors. A ray's
 * equation is given by:
 *
 * 		P = O + tD
 *
 * P - The point at t direction vectors
 * O - The ray's origin
 * t - Distance factor
 * D - The ray' direction
 *
 * @param ray The casted ray
 * @param t The distance factor
 * @return t_vec3 The point at t
 */
t_vec3	ray_at(t_ray *ray, double t);
