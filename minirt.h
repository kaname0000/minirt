/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:43:06 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:52:14 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "color/color.h"
# include "mlx/mlx.h"
# include "paser/paser.h"
# include "vector/vec.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define EPSILON 0.001

bool	is_zerovec(t_vec vec);
t_color	ambient_light(t_color ambient, t_color obj, int flag);
t_color	diffuse_reflection(t_light *light, t_insec insec, int type);
t_color	specular_reflection(t_ray ray, t_insec insec, t_light *light);
void	raytracing(t_world *world);
void	my_mlx_pixel_put(t_world *world, int x, int y, int color);
t_insec	trace_nearest(t_ray ray, t_obj *obj);
t_vec	ray_dir(t_world *world, t_camera *camera, int i, int j);
void	in_shadow(t_insec *insec, t_obj *obj, t_light *light);

#endif