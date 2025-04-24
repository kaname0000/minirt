/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reffuese_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 05:57:46 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 05:57:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int apply_diffuse_color(double diffuse)
{
    if (diffuse == 0.0)
        return(0x006495EC);
    if (diffuse > 1.0)
        diffuse = 1.0;
    int color = (int)(255 * diffuse);
    return (color << 16 | color << 8 | color);
}
