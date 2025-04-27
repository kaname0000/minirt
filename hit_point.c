/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:11:59 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 19:06:25 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
