/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 22:22:31 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "paser/paser.h"
#include <stdio.h>

void	input_init(t_world *world)
{
	world->input.move_forward = false;
	world->input.move_backward = false;
	world->input.move_left = false;
	world->input.move_right = false;
	world->input.look_right = false;
	world->input.look_left = false;
	world->input.look_up = false;
	world->input.look_down = false;
	world->input.moza_down = false;
	world->input.moza_up = false;
}

void	window_init(t_world *world)
{
	world->mlx = mlx_init();
	if (!world->mlx)
		exit(1);
	world->win = mlx_new_window(world->mlx, world->screen_width,
			world->screen_height, "minirt");
	if (!world->win)
	{
		free(world->mlx);
		exit(1);
	}
	world->img = mlx_new_image(world->mlx, world->screen_width,
			world->screen_height);
	world->addr = mlx_get_data_addr(world->img, &world->bits_per_pixel,
			&world->line_length, &world->endain);
	input_init(world);
}

int	main(int argc, char *argv[])
{
	t_world	world;

	(void)argc;
	world.screen_width = 1000;
	world.screen_height = 1000;
	world.objects = NULL;
	world.mosaic_size = 1;
	window_init(&world);
	paser(&world, argv[1]);
	world.obj_array = list_to_array(world.objects);
	world.bvh = build_bvh(world.obj_array.obj_array, 0, world.obj_array.count);
	raytracing(&world);
	printf("計算終わったよ\n");
	mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
	setup_hooks(&world);
	mlx_loop(world.mlx);
	return (0);
}
