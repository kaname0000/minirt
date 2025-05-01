/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:06:40 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 21:01:20 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

int	apply_diffuse_color(double R, t_color color)
{
	if (R == 0.0)
		return (0x006495EC);
	if (R > 1.0)
		R = 1.0;
	return ((int)(color.red * R) << 16 | (int)(color.green
			* R) << 8 | (int)(color.blue * R));
}
