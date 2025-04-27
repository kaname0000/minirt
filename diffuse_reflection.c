/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:44:15 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:11:41 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	diffuse_reflection(t_vec light, t_vec intersection, t_vec sphere)
{
	t_vec	n;
	t_vec	l;
	double	r;

	n = vec_normalize(vec_sub(intersection, sphere));
	l = vec_normalize(vec_sub(light, intersection));
	r = vec_dot(n, l);
	if (is_zerovec(intersection))
		return (0);
	if (r < 0)
		r = 0;
	return (r * 0.69);
}
