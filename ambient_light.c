/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:02:44 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 16:12:31 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ambient_light(t_vec intersection, double k, double i)
{
	if (is_zerovec(intersection))
		return (0);
	return (k * i);
}
