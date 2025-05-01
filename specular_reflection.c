/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_reflection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:08:41 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 21:04:49 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// double	specular_reflection(t_vec camera, t_vec intersection, t_vec light,
// 		t_vec sphere)
// {
// 	t_vec	v;
// 	t_vec	l;
// 	t_vec	n;
// 	t_vec	r;
// 	double	rdotv;

// 	if (is_zerovec(intersection))
// 		return (0);
// 	v = vec_normalize(vec_sub(camera, intersection));
// 	l = vec_normalize(vec_sub(light, intersection));
// 	n = vec_normalize(vec_sub(intersection, sphere));
// 	r = vec_normalize(vec_sub(vec_mult(n, 2 * vec_dot(n, l)), l));
// 	rdotv = vec_dot(r, v);
// 	if (rdotv < 0)
// 		rdotv = 0;
// 	return (0.3 * pow(rdotv, 8));
// }

double	specular_reflection(t_ray ray, t_insec insec, t_light *light)
{
	t_vec	l;
	t_vec	r;
	double	rdotv;

	if (!insec.flag)
		return (0);
	l = vec_normalize(vec_sub(insec.insec, light->pos));
	r = vec_normalize(vec_sub(vec_mult(insec.normal, 2 * vec_dot(insec.normal,
						l)), l));
	rdotv = vec_dot(r, ray.dir);
	if (rdotv < 0)
		rdotv = 0;
	return (0.3 * pow(rdotv, 8));
}
