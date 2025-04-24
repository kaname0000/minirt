/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 05:15:49 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 05:15:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double diffuse_reflection(t_vec light, t_vec intersection, t_vec sphere)
{
    t_vec N = vec_normalize(vec_sub(intersection, sphere));
    t_vec L = vec_normalize(vec_sub(light,intersection));
    double R = vec_dot(N, L);
    if(is_zerovec(intersection))
        return(0);
    if (R < 0)
        R = 0;
    return (R+0.1);
}