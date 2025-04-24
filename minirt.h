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
#include <stdio.h>
#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdbool.h>

enum e_objtype{
    SP,
    PL,
    C,
    TR,
    SQ,
    CY
};

typedef struct s_list
{
    double x;
    double y;
    double z;
    enum e_objtype type;
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
    void	    *img;
	char	    *addr;
    int		bits_per_pixel;
	int		line_length;
    int         endain;
    int        screen_width;
    int        screen_height;
    t_dlist *cameras;  
    t_list      *objects;  
    t_color    ambient;  
    t_list      *lights;
}               t_world;

t_vec hit_intersection_s(t_vec sphere,t_vec camera,t_vec screen,double r);
bool is_zerovec(t_vec vec);
double diffuse_reflection(t_vec light,t_vec intersection,t_vec sphere);

#endif