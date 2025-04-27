/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:04:50 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:05:03 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 作成
t_color	color_init(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}
