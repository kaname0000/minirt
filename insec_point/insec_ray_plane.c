/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:56:06 by okaname           #+#    #+#             */
/*   Updated: 2025/05/11 18:09:04 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_ray_plane(t_ray ray, t_plane plane)
{
	double	t;
	double	n;

	n = vec_dot(ray.dir, plane.normal);
	if (n < 1e-6)
		return (0);
	t = vec_dot(vec_sub(plane.pos, ray.start), plane.normal) / n;
	if (t <= 0)
		return (0);
	return (t);
}
