/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_reflection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:08:41 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 09:40:15 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	specular_reflection(t_vec camera, t_vec intersection, t_vec light,
		t_vec sphere)
{
	t_vec	V;
	t_vec	L;
	t_vec	N;
	t_vec	R;
	double	RdotL;

	if (is_zerovec(intersection))
		return (0);
	V = vec_normalize(vec_sub(camera, intersection));
	L = vec_normalize(vec_sub(light, intersection));
	N = vec_normalize(vec_sub(intersection, sphere));
	R = vec_normalize(vec_sub(vec_mult(N, 2 * vec_dot(N, L)), L));
	RdotL = vec_dot(R, L);
	if (RdotL < 0)
		RdotL = 0;
	return (0.3 * pow(RdotL, 8));
}
