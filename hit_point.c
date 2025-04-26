/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/25 05:31:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 05:31:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static double	hit_sphere(t_vec sphere, t_vec camera, t_vec screen, double r)
{
	t_vec ray = vec_sub(screen, camera); // レイの方向
	t_vec oc = vec_sub(camera, sphere);  // カメラ → 球中心ベクトル

	double A = vec_dot(ray, ray);
	double B = 2 * vec_dot(ray, oc);
	double C = vec_dot(oc, oc) - r * r;
	double D = B * B - 4 * A * C;

	if (D <= 0)
		return (0); // 交差しない

	double sqrtD = sqrt(D);
	double t1 = (-B - sqrtD) / (2 * A);
	double t2 = (-B + sqrtD) / (2 * A);

	if (t1 > 0)
		return (t1);
	if (t2 > 0)
		return (t2);
	return (0);
}

t_vec	hit_intersection_s(t_vec sphere, t_vec camera, t_vec screen, double r)
{
	double t;
	t_vec ray;
	t_vec intersection;

	t = hit_sphere(sphere, camera, screen, r);
	if (t == 0.0)
		return (vec_init(0, 0, 0));
	ray = vec_sub(screen, camera);
	intersection = vec_add(vec_mult(ray, t), camera);
	
	return (intersection);
}
