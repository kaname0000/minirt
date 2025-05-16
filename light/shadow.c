/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:00:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:29:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../insec_point/insec.h"
#include "../minirt.h"

void	in_shadow(t_insec *insec, t_obj *obj, t_light *light)
{
	t_obj	*tmp;
	t_ray	ray;
	double	t;
	double	light_dist;

	ray.start = insec->insec;
	ray.dir = vec_normalize(vec_sub(light->pos, insec->insec));
	light_dist = vec_mag(vec_sub(light->pos, insec->insec));
	tmp = obj;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = intersect_ray_sphere(ray, tmp->u_object.sphere);
		else if (tmp->type == PLANE)
			t = intersect_ray_plane(ray, tmp->u_object.plane);
		else if (tmp->type == CYLINDER)
			t = intersect_ray_cylinder(ray, tmp->u_object.cylinder);
		else if (tmp->type == TRIANGLE)
			t = intersect_ray_triangle(ray, tmp->u_object.triangle);
		else
		{
			tmp = tmp->next;
			continue ;
		}
		if (t > EPSILON && t < light_dist)
		{
			insec->flag = 0;
			return ;
		}
		tmp = tmp->next;
	}
}
