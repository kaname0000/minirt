/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:00:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 19:30:07 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../insec_point/insec.h"
#include "../minirt.h"
#include <stdbool.h>

bool	hit_aabb(t_ray ray, t_aabb box, double max_dist)
{
	double	tmin;
	double	tmax;
	double	invD;
	double	origin;
	double	dir;
	double	min;
	double	max;
	double	temp;

	tmin = 0.0;
	tmax = max_dist;
	for (int i = 0; i < 3; i++)
	{
		double t0, t1;
		origin = (&ray.start.x)[i];
		dir = (&ray.dir.x)[i];
		min = (&box.min.x)[i];
		max = (&box.max.x)[i];
		if (dir == 0.0)
		{
			if (origin < min || origin > max)
				return (false);
			else
				continue ;
		}
		invD = 1.0 / dir;
		t0 = (min - origin) * invD;
		t1 = (max - origin) * invD;
		if (invD < 0.0)
		{
			temp = t0;
			t0 = t1;
			t1 = temp;
		}
		if (t0 > tmin)
			tmin = t0;
		if (t1 < tmax)
			tmax = t1;
		if (tmax <= tmin)
			return (false);
	}
	return (true);
}

static double	intersect_object(t_ray ray, t_obj *obj)
{
	t_obj	*tmp;
	double	t;
	double	t_min;

	tmp = obj;
	t_min = -1;
	while (obj)
	{
		t = -1;
		if (obj->type == SPHERE)
			t = intersect_ray_sphere(ray, obj->u_object.sphere);
		else if (obj->type == PLANE)
			t = intersect_ray_plane(ray, obj->u_object.plane);
		else if (obj->type == CYLINDER)
			t = intersect_ray_cylinder(ray, obj->u_object.cylinder);
		else if (obj->type == TRIANGLE)
			t = intersect_ray_triangle(ray, obj->u_object.triangle);
		if (t > 0 && (t_min < 0 || t < t_min))
			t_min = t;
		obj = obj->next;
	}
	return (t_min);
}

bool	trace_shadow_bvh(t_ray ray, t_bvh_node *node, double max_dist)
{
	double	t;

	if (!node || !hit_aabb(ray, node->box, max_dist))
		return (false);
	if (node->obj)
	{
		t = intersect_object(ray, node->obj);
		return (t > EPSILON && t < max_dist);
	}
	if (trace_shadow_bvh(ray, node->left, max_dist))
		return (true);
	if (trace_shadow_bvh(ray, node->right, max_dist))
		return (true);
	return (false);
}

void	in_shadow(t_insec *insec, t_bvh_node *bvh, t_light *light)
{
	t_ray	ray;
	double	light_dist;

	ray.dir = vec_normalize(vec_sub(light->pos, insec->insec));
	ray.start = vec_add(insec->insec, vec_mult(ray.dir, EPSILON));
	light_dist = vec_mag(vec_sub(light->pos, insec->insec));
	if (trace_shadow_bvh(ray, bvh, light_dist))
		insec->flag = 0;
}
