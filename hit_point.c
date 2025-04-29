/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:11:59 by okaname           #+#    #+#             */
/*   Updated: 2025/04/29 22:53:08 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	(void)insec;
	(void)obj;
	return (vec_init(0, 0, 0));
}

double	intersect_ray_sphere(t_ray ray, t_sphere sphere)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	oc = vec_sub(ray.start, sphere.pos);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(ray.dir, oc);
	c = vec_dot(oc, oc) - sphere.rad * sphere.rad;
	d = b * b - 4 * a * c;
	if (d <= 0)
		return (0);
	if ((-b - sqrt(d)) / (2.0 * a) > 0)
		return ((-b - sqrt(d)) / (2.0 * a));
	if ((-b + sqrt(d)) / (2.0 * a) > 0)
		return ((-b + sqrt(d)) / (2.0 * a));
	return (-1);
}

double	intersect_ray_plane(t_ray ray, t_plane plane)
{
	(void)ray;
	(void)plane;
	return (0);
}

double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	(void)ray;
	(void)cylinder;
	return (0);
}

void	insec_info(t_ray ray, t_obj *obj, t_insec *insec, double t)
{
	insec->flag = 1;
	if (obj->type == SPHERE)
	{
		insec->color = obj->u_object.sphere.color;
		insec->insec = vec_add(ray.start, vec_mult(ray.dir, t));
		insec->normal = vec_sub(insec->insec, obj->u_object.sphere.pos);
	}
	else if (obj->type == PLANE)
	{
		insec->color = obj->u_object.plane.color;
		insec->insec = vec_add(ray.start, vec_mult(ray.dir, t));
		insec->normal = obj->u_object.plane.normal;
	}
	else if (obj->type == CYLINDER)
	{
		insec->color = obj->u_object.cylinder.color;
		insec->insec = vec_add(ray.start, vec_mult(ray.dir, t));
		insec->normal = get_cylinder_normal(insec->insec, obj);
	}
	insec->normal = vec_normalize(insec->normal);
}

t_insec	trace_nearest(t_ray ray, t_obj *obj)
{
	t_obj	*tmp;
	t_insec	insec;
	double	t_min;
	double	t;

	tmp = obj;
	t_min = -1.0;
	insec.flag = 0;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			t = intersect_ray_sphere(ray, tmp->u_object.sphere);
		else if (tmp->type == PLANE)
			t = intersect_ray_plane(ray, tmp->u_object.plane);
		else if (tmp->type == CYLINDER)
			t = intersect_ray_cylinder(ray, tmp->u_object.cylinder);
		if (t > 0 && (t_min < 0 || t < t_min))
		{
			t_min = t;
			insec_info(ray, tmp, &insec, t_min);
		}
		tmp = tmp->next;
	}
	return (insec);
}

static double	hit_sphere(t_vec sphere, t_vec camera, t_vec screen, double r)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	sqrtd;
	double	t1;
	double	t2;
	t_vec	ray;
	t_vec	oc;

	ray = vec_sub(screen, camera);
	oc = vec_sub(camera, sphere);
	a = vec_dot(ray, ray);
	b = 2 * vec_dot(ray, oc);
	c = vec_dot(oc, oc) - r * r;
	d = b * b - 4 * a * c;
	if (d <= 0)
		return (0);
	sqrtd = sqrt(d);
	t1 = (-b - sqrtd) / (2 * a);
	t2 = (-b + sqrtd) / (2 * a);
	if (t1 > 0)
		return (t1);
	if (t2 > 0)
		return (t2);
	return (0);
}

t_vec	hit_intersection(t_vec sphere, t_vec camera, t_vec screen, double r)
{
	double	t;
	t_vec	ray;
	t_vec	intersection;

	t = hit_sphere(sphere, camera, screen, r);
	if (t == 0.0)
		return (vec_init(0, 0, 0));
	ray = vec_sub(screen, camera);
	intersection = vec_add(vec_mult(ray, t), camera);
	return (intersection);
}
