/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_const_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:42:07 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:42:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 定数倍
t_color color_const_mult(t_color c,double k)
{
    t_color color;

    color.red=c.red * k;
    color.green=c.green * k;
    color.blue=c.bule * k;
    return(color);
}