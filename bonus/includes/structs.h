/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:10:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 13:27:43 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @brief Represents a tridimensional vector
 * @param x The x component
 * @param y The y component
 * @param z The z component
 */
typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

/**
 * @brief Represents a color by its components
 * @param t The transparency component
 * @param r The red component
 * @param g The green component
 * @param b The blue component
 */
typedef struct s_color
{
	int				t;
	int				r;
	int				g;
	int				b;
}					t_color;

/**
 * @brief A scene's ray
 *
 * @param origin The origin of the ray
 * @param direction The direction of the ray
 */
typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

/**
 * @brief Describes how the camera is positioned in the scene
 *
 * @param center The center of the camera
 * @param normal The direction of the camera
 * @param fov The camera's Field Of View
 */
typedef struct s_camera
{
	t_vec3			center;
	t_vec3			normal;
	double			fov;
}					t_camera;

/**
 * @brief Used to represent both the ambient light and a light source.
 *
 * @param center The center of the light source
 * @param ratio The ratio/brightness of the light
 * @param color The light's color
 *
 * @note The center field is not used in ambient lighting
 */
typedef struct s_light
{
	t_vec3			center;
	double			ratio;
	t_color			color;
}					t_light;

/**
 * @brief Describes what shape you're dealing with
 */
typedef enum s_shape_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
}					t_shape_type;

/**
 * @brief Describes a sphere
 *
 * @param center The center of the sphere
 * @param radius The radius of the sphere
 * @param color The color of the sphere
 */
typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	t_color			color;
}					t_sphere;

/**
 * @brief Describes an infinite plane
 *
 * @param center A point in the plane (not really its center)
 * @param normal The direction the plane is pointing at
 * @param color The color of the plane
 */
typedef struct s_plane
{
	t_vec3			center;
	t_vec3			normal;
	t_color			color;
}					t_plane;

/**
 * @brief Describes a cylinder
 *
 * @param center The center of a cylinder
 * @param cap The cap point of the plane calculated using:
 *
 * 		cap_base = center - height/2 * Normal t_vec3
 *
 * @param base The base point of the plane calculated using:
 *
 * 		cap_top = center + height/2 * Normal t_vec3
 *
 * @param normal The direction of the cylinder
 * @param radius The radius of the cylinder
 * @param height The height of the cylinder
 * @param color The color of the cylinder
 */
typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			cap_top;
	t_vec3			cap_base;
	t_vec3			normal;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;

/**
 * @brief Describes a cone
 *
 * @param tip The tip of the cone
 * @param base The base of the cone
 * @param normal The direction of the cone
 * @param height The height of the cone
 * @param radius The radius of the cone
 * @param angle The half angle of the cone
 * @param color The color of the cone
 */
typedef struct s_cone
{
	t_vec3			tip;
	t_vec3			base;
	t_vec3			normal;
	double			height;
	double			radius;
	double			angle;
	t_color			color;
}					t_cone;

/**
 * @brief Contains the data of only ONE of the shapes at a time.
 * This means that if the cylinder is used, reading from the plane or
 * sphere will give you random values.
 *
 * @param sp The t_sphere struct
 * @param pl The t_plane struct
 * @param cy The t_cylinder struct
 * @param cn The t_cone struct
 */
typedef union u_data
{
	t_sphere		sp;
	t_plane			pl;
	t_cylinder		cy;
	t_cone			cn;
}					t_data;

/**
 * @brief Describes a shape
 *
 * @param data The union containing the shape data
 * @param type The type of shape
 * @param id A number between 0 and the number of shapes in the scene
 * @param shininess Exponent that influences the size and spread
 *	of the specular reflection
 * @param sp_ratio The intensity of specular reflection
 */
typedef struct s_shape
{
	t_data			data;
	t_shape_type	type;
	int				id;
	double			sp_ratio;
	double			shininess;
}					t_shape;

/**
 * @brief Contains the necessary fields to handle both second degree
 * and linear equations.
 *
 * @param a The a value
 * @param b The b value
 * @param c The c value
 * @param t1 The first root
 * @param t2 The second root
 */
typedef struct s_equation
{
	double			a;
	double			b;
	double			c;
	double			t1;
	double			t2;
}					t_equation;

/**
 * @brief Contains mlx related variables
 *
 * @param mlx The mlx pointer
 * @param win The mlx window pointer
 * @param img The mlx image frame pointer
 * @param addr The address of the first byte of the mlx image
 * @param height The image's height
 * @param width The image's width
 * @param bpp The bytes per pixel in the image pointer
 * @param line_length (not used)
 * @param endian (not used)
 */
typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				height;
	int				width;
	int				bpp;
	int				line_length;
	int				endian;
}					t_graphics;

/**
 * @brief Describes an intersection point in the scene between
 * a ray and a shape.
 *
 * @param shape The shape that was hit
 * @param ray The ray that hit the shape
 * @param point The intersection point
 * @param normal The normal of the shape in the intersection point
 * @param color The color of the hit shape
 * @param a Used to know where the ray hit in a cylinder's axis
 * @param t The distance between the hit the ray's origin
 * @param m Additional information specific to the shape
 * (e.g., height or distance along the axis)
 */
typedef struct s_hit
{
	t_shape			*shape;
	t_ray			ray;
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
	t_vec3			a;
	double			t;
	double			m;
}					t_hit;

/**
 * @brief The primary struct, contains everything needed to describe a scene
 *
 * @param camera The scene's camera
 * @param ambient The scene's ambient light
 * @param shapes The scene's shapes vector
 * @param counters The number of A, C and L entities found when parsing
 * @param disp The mlx variables
 * @param up The viewport up vector
 * @param right The viewport right vector
 * @param map The map read from the given file
 * @param hview The height of the viewport
 * @param wview The width of the viewport
 */
typedef struct s_scene
{
	t_camera		camera;
	t_light			ambient;
	int				counters[3];
	t_graphics		disp;
	t_vector		*shapes;
	t_vector		*lights;
	t_vec3			up;
	t_vec3			right;
	char			**map;
	double			hview;
	double			wview;
}					t_scene;

#endif
