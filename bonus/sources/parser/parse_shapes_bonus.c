/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:28:42 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_sphere	sphere;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 6)
		return (error_returner("ERROR_NUM_ARGS", "sphere", 6), false);
	if (!parse_syntax(tokens, "010100"))
		return (error_returner("ERROR_NUM_COMMAS", "sphere", 0), false);
	if (!parse_rgb(tokens[3]))
		return (error_returner("ERROR_MISFORMAT_COLOR", "sphere", 0), false);
	if (ft_atod(tokens[4]) < 0.0 || ft_atod(tokens[4]) > 1.0)
		return (error_returner("ERROR_KS_OUT_OF_BOUNDS", "sphere", 0), false);
	if (ft_atod(tokens[5]) < 0.0)
		return (error_returner("ERROR_SHININESS_OUT_OF_BOUNDS", "sphere", 0),
			false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (error_returner("ERROR_VALUES_TOO_SMALL", "plane", 0), false);
	shape = shape_new(&sphere, SPHERE, shapes->size, tokens + 4);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (ft_matrix_size(tokens) != 6)
		return (error("Wrong number of args in plane (need 4)"), false);
	if (!parse_syntax(tokens, "0111"))
		return (error("Misconfiguration in commas/numbers in plane"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in plane"), false);
	if (ft_atod(tokens[4]) < 0.0 || ft_atod(tokens[4]) > 1.0)
		return (error_returner("ERROR_KS_OUT_OF_BOUNDS", "plane", 0), false);
	if (ft_atod(tokens[5]) < 0.0)
		return (error_returner("ERROR_SHININESS_OUT_OF_BOUNDS", "plane", 0),
			false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (error("Values are too small in plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size, tokens + 4);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 8)
		return (error("Wrong number of args in cylinder (need 6)"), false);
	if (!parse_syntax(tokens, "011001"))
		return (error("Misconfiguration in commas/numbers in cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (error("Colors misformatting in cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (ft_atod(tokens[6]) < 0.0 || ft_atod(tokens[6]) > 1.0)
		return (error_returner("ERROR_KS_OUT_OF_BOUNDS", "cylinder", 0), false);
	if (ft_atod(tokens[7]) < 0.0)
		return (error_returner("ERROR_SHININESS_OUT_OF_BOUNDS", "cylinder", 0),
			false);
	if (!ok)
		return (error("Values are too small in cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_cone(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_cone	cone;
	t_shape	*shape;

	if (ft_matrix_size(tokens) != 8)
		return (error_returner("ERROR_NUM_ARGS", "cone", 8), false);
	if (!parse_syntax(tokens, "01100100"))
		return (error_returner("ERROR_NUM_COMMAS", "cone", 0), false);
	if (!parse_rgb(tokens[5]))
		return (error_returner("ERROR_MISFORMAT_COLOR", "cone", 0), false);
	ok = cone_from_strings(&cone, tokens);
	if (ft_atod(tokens[6]) < 0.0 || ft_atod(tokens[6]) > 1.0)
		return (error_returner("ERROR_KS_OUT_OF_BOUNDS", "cone", 0), false);
	if (ft_atod(tokens[7]) < 0.0)
		return (error_returner("ERROR_SHININESS_OUT_OF_BOUNDS", "cone", 0),
			false);
	if (!ok)
		return (error_returner("ERROR_VALUES_TOO_SMALL", "cone", 0), false);
	shape = shape_new(&cone, CONE, shapes->size, tokens + 6);
	ft_vector_push(shapes, shape);
	return (true);
}
