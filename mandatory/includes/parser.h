/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:40:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:21:08 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//TO-DO: add Doxygen for the functions below

bool	parse_syntax(char **tokens, char *code);

bool	parse_double(char **nb);

void	parse_map(t_scene *scene, char **map, int counters[3]);

bool	parse_entity(t_scene *scene, char **tokens, int count[3]);

bool	parse_rgb(char *color);

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3]);

bool	parse_camera(t_camera *cam, char **tokens, int counters[3]);

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3]);

t_scene	*parse(char *filename);

char	**read_map(t_scene *scene, char *filename);

bool	is_filename_valid(char *filename);

bool	parse_sphere(t_vector *shapes, char **tokens);

bool	parse_plane(t_vector *shapes, char **tokens);

bool	parse_cylinder(t_vector *shapes, char **tokens);
