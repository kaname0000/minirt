/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:55 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:05:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 範囲を0~255⇒0~1
t_color	color_normalize(t_color c)
{
	t_color	color;

	color.red = c.red / 255;
	color.green = c.green / 255;
	color.blue = c.blue / 255;
	return (color);
}
