/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/04 20:42:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_world(t_world *world)
{
	t_vec	camera;
	t_vec	sphere;

	sphere = vec_init(0, 0, 5);
	camera = vec_init(7, -1, -3);
	world->cameras = make_camera(camera, vec_sub(sphere, camera), 70,
			world->screen_width);
	world->lights = make_light(vec_init(5, -10, -5), 1, color_init(100, 100,
				100));
	world->objects = make_sphere(sphere, 4, color_init(255, 100, 100));
	world->objects->next = make_sphere(vec_init(0, 0, 9), 4, color_init(100,
				100, 100));
	world->objects->next->next = make_sphere(vec_init(0, 0, 13), 4,
			color_init(100, 100, 255));
	world->objects->next->next->next = make_sphere(vec_init(0, 0, 17), 4,
			color_init(100, 255, 100));
}

int	main(void)
{
	t_world	world;

	world.screen_width = 1000;
	world.screen_height = 1000;
	world.mlx = mlx_init();
	if (!world.mlx)
		return (1);
	world.win = mlx_new_window(world.mlx, world.screen_width,
			world.screen_height, "minirt");
	if (!world.win)
		return (free(world.mlx), 1);
	world.img = mlx_new_image(world.mlx, world.screen_width,
			world.screen_height);
	world.addr = mlx_get_data_addr(world.img, &world.bits_per_pixel,
			&world.line_length, &world.endain);
	make_world(&world);
	raytracing(&world);
	mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
	mlx_loop(world.mlx);
	return (0);
}
