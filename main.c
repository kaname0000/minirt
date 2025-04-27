/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:49 by okaname           #+#    #+#             */
/*   Updated: 2025/04/28 03:47:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_world(t_world *world)
{
	(void)world;
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
	raytracing(&world);
	mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
	mlx_loop(world.mlx);
	return (0);
}
