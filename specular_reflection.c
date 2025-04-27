/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_reflection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:08:41 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:13:55 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	specular_reflection(t_vec camera, t_vec intersection, t_vec light,
		t_vec sphere)
{
	t_vec	v;
	t_vec	l;
	t_vec	n;
	t_vec	r;
	double	rdotl;

	if (is_zerovec(intersection))
		return (0);
	v = vec_normalize(vec_sub(camera, intersection));
	l = vec_normalize(vec_sub(light, intersection));
	n = vec_normalize(vec_sub(intersection, sphere));
	r = vec_normalize(vec_sub(vec_mult(n, 2 * vec_dot(n, l)), l));
	rdotl = vec_dot(r, l);
	if (rdotl < 0)
		rdotl = 0;
	return (0.3 * pow(rdotl, 8));
}
