/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:31:09 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:31:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 作成
t_color color_init(double red,double green,double blue)
{
    t_color color;

    color.red=red;
    color.green=green;
    color.blue=blue;
    return(color);
}