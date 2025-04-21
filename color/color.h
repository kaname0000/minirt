/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:29:45 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:29:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
    double red;
    double green;
    double blue;
}t_color;

t_color color_init(double red,double green,double blue);
t_color color_normalize(t_color c);
t_color color_add(t_color c1,t_color c2);
t_color color_mult(t_color c1,t_color c2);

#endif