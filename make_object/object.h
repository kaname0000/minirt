/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:37:33 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 19:18:53 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../color/color.h"
# include "../vector/vec.h"
# include <unistd.h>

enum				e_objtype
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_sphere
{
	t_vec			pos;
	double			dia;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_vec			pos;
	t_vec			normal;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_vec			pos;
	double			dia;
	double			height;
	t_color			color;
}					t_cylinder;

typedef struct s_obj
{
	enum e_objtype	type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	} u_object;
	struct s_obj	*next;
}					t_obj;

typedef struct s_camera
{
	t_vec			pos;
	t_vec			dir;
	double			fov;
}					t_camera;

typedef struct s_light
{
	t_vec			pos;
	double			brightness;
	t_color			color;
	struct s_light	*next;
}					t_light;

t_obj				*make_cyl(t_vec pos, double dia, double height,
						t_color color);
t_obj				*make_plane(t_vec pos, t_vec normal, t_color color);
t_obj				*make_sphere(t_vec pos, double dia, t_color color);
t_camera			*make_camera(t_vec pos, t_vec dir, double fob);

#endif