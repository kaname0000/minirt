/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :*:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:39:25 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:39:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 積
t_color color_mult(t_color c1,t_color c2)
{
    t_color color;

    color.red=c1.red * c2.red;
    color.green=c1.green * c2.green;
    color.blue=c1.bule * c2.blue;
    return(color);
}