/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/26 04:25:29 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 04:25:29 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


double	diffuse_reflection(t_vec light, t_vec intersection, t_vec sphere)
{
	t_vec N;
	t_vec L;
	double R;

	N = vec_normalize(vec_sub(intersection, sphere));
	L = vec_normalize(vec_sub(light, intersection));
	R = vec_dot(N, L);
	if (is_zerovec(intersection))
		return (0);
	if (R < 0)
		R = 0;
	return (R * 0.69);
}
