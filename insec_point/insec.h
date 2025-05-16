/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:58:01 by okaname           #+#    #+#             */
/*   Updated: 2025/05/12 22:08:05 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSEC_H
# define INSEC_H

# include "../minirt.h"

t_vec	get_cylinder_normal(t_vec insec, t_obj *obj);
double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder);
double	intersect_ray_plane(t_ray ray, t_plane plane);
double	intersect_ray_sphere(t_ray ray, t_sphere sphere);
double	intersect_ray_triangle(t_ray ray, t_triangle triangle);

#endif