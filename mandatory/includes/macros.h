/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:28:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 11:07:23 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define HAS_COMMAS '1'

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 1440
# else
#  define WIDTH 1920
# endif

# define HEIGHT 1080

//! Minilibx events

# ifdef __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define V 9
#  define KEY_PRESS 2
#  define DESTROY_NOTIFY 17
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define V 118
# endif

//! Math macros

# define PI 3.1415926535f
# define EPSILON 0.0001

//! Error macros

# define ERROR_MALLOC  		"Failed allocation on."
# define ERROR_USAGE 		"Usage: ./miniRT <scene>.rt"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_OPEN_FILE	"Couldn't open requested file"
# define ERROR_NOT_RT		"File extension is not '.rt'."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."
# define ERROR_TOO_MANY		"Found more than 1 A or C or L entities"

#endif
