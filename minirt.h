/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:45:43 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 04:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include "color/color.h"
#include "vector/vec.h"

enum objtype{
    SP;
    PL;
    C;
    TR;
    SQ;
    CY;
}

typedef struct s_list
{
    double x;
    double y;
    double z;
    enum objtype;
    struct s_list *next;
    
}t_list;

typedef struct s_dlist
{
    double x;
    double y;
    double z;
    struct s_dlist *next;
    
}t_dlist;

typedef struct s_world {
    void       *mlx;  
    void       *win;  
    int        screen_width;
    int        screen_height;
    t_dlist *cameras;  
    t_list      *objects;  
    t_color    ambient;  
    t_list      *lights;
}               t_world;

#endif