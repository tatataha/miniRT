/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:23:45 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool			ok;
	t_sphere		sphere;
	t_shape			*shape;

	if (ft_matrix_size(tokens) != 4)
		return (error("Wrong number of args in sphere (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (error("Misconfiguration in commas/numbers in sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misforma*tting in sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (error("Values are too small in sphere"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (ft_matrix_size(tokens) != 4)
		return (error("Wrong number of args in plane (need 4)"), false);
	if (!parse_syntax(tokens, "0111"))
		return (error("Misconfiguration in commas/numbers in plane"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (error("Values are too small in plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 6)
		return (error("Wrong number of args in cylinder (need 6)"), false);
	if (!parse_syntax(tokens, "011001"))
		return (error("Misconfiguration in commas/numbers in cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (error("Colors misformatting in cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (error("Values are too small in cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}
