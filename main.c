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

void raytracing()
{
    t_vec camera_vec;
    camera_vec = vec_init(0, 0, -5);  // スクリーンの少し手前な感じ

    printf("%f\n",camera_vec.z);
    // 球の中心座標
    t_vec sphere_vec;
    sphere_vec = vec_init(0, 0, 5);  // スクリーンの少し奥な感じ
    printf("%f\n",sphere_vec.z); 
}

void	my_mlx_pixel_put(t_world *world, int x, int y, int color)
{
	char	*dst;

	dst = world->addr + (y * world->line_length + x * (world->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
    mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
    mlx_loop(world.mlx);
    // raytracing();
    return(0);
}