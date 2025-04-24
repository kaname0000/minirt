/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:18:54 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 14:18:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_world *world, int x, int y, int color)
{
	char	*dst;

	dst = world->addr + (y * world->line_length + x * (world->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void raytracing(t_world* world)
{
    int i;
    int j;
    t_vec camera;
    camera = vec_init(0, 0, -5);
    t_vec sphere;
    sphere = vec_init(0, 0, 5);
    t_vec light;
    light = vec_init(-5,5,-5);
    i=0;
    while(i<world->screen_width)
    {
        j=0;
        while(j<world->screen_height)
        {
            int color = apply_diffuse_color(diffuse_reflection(light,
                hit_intersection_s(sphere,
                camera,vec_init(((double)i / world->screen_width) * 2.0 - 1.0,
                1.0 - ((double)j / world->screen_height) * 2.0,0),1),
                sphere));
                my_mlx_pixel_put(world,i,j,color);
            j++;
        }
        i++;
    }
}

// void raytracing(t_world* world)
// {
//     int i, j;
//     t_vec camera_vec = vec_init(0, 0, -5);
//     t_vec sphere_vec = vec_init(0, 0, 5);

//     for (i = 0; i < world->screen_width; i++)
//     {
//         for (j = 0; j < world->screen_height; j++)
//         {
//             double x = ((double)i / world->screen_width) * 2.0 - 1.0;
//             double y = ((double)j / world->screen_height) * 2.0 - 1.0;
//             t_vec screen = vec_init(x, y, 0);

//             if (hit_sphere(sphere_vec, camera_vec, screen, 1))
//                 my_mlx_pixel_put(world, i, j, 0x00000000);  // blue
//             else
//                 my_mlx_pixel_put(world, i, j, 0x006495EC);  // red
//         }
//     }
// }

int main()
{
    t_world world;

    world.screen_width=1000;
    world.screen_height=1000;
    world.mlx=mlx_init();
    if(!world.mlx)
        return(1);
    world.win = mlx_new_window(world.mlx, world.screen_width,world.screen_height,"minirt");
    if (!world.win)
		return (free(world.mlx),1);
    world.img = mlx_new_image(world.mlx, world.screen_width,world.screen_height);
    world.addr = mlx_get_data_addr(world.img, &world.bits_per_pixel,&world.line_length, &world.endain);
    raytracing(&world);
    mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
    mlx_loop(world.mlx);
    return(0);
}