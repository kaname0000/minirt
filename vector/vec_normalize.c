/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/22 04:22:30 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:22:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"


// 正規化
t_vec	vec_normalize(t_vec v)
{
	t_vec vec;
	double mag;

	mag = vec_mag(v);
	vec.x = v.x / mag;
	vec.y = v.y / mag;
	vec.z = v.z / mag;
	return (vec);
}
