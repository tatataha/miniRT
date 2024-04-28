/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:01:35 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:22:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	error(char *message)
{
	printf("Error\n%s\n", message);
}

void	error_returner(char *type, char *txt, int n)
{
	if (!ft_strcmp(type, "ERROR_NUM_ARGS"))
		printf("Wrong number of args in \"%s\" (need \"%d\")\n", txt, n);
	else if (!ft_strcmp(type, "ERROR_NUM_COMMAS"))
		printf("Too many/few commas in \"%s\"\n", txt);
	else if (!ft_strcmp(type, "ERROR_LIGHT_BRIGHTNESS_OUT_OF_BOUNDS"))
		printf("t_light brightness out of bounds [0.0,1.0]\n");
	else if (!ft_strcmp(type, "ERROR_VALUES_TOO_SMALL"))
		printf("Values are too small in \"%s\"\n", txt);
	else if (!ft_strcmp(type, "ERROR_KS_OUT_OF_BOUNDS"))
		printf("Specular coefficient out of bounds in \"%s\" [0.0,1.0]\n", txt);
	else if (!ft_strcmp(type, "ERROR_MISFORMAT_COLOR"))
		printf("Colors misformatting in \"%s\"\n", txt);
}

void	message(t_scene *scene, char *text)
{
	scene_destroy(&scene);
	printf("\033[1;31mERROR\033[0m\n%s\n", text);
	exit(EXIT_FAILURE);
}
