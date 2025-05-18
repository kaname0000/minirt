/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 19:30:55 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "paser/paser.h"
#include <stdio.h>

void	print_bvh(t_bvh_node *node, int depth)
{
	int		count;
	t_obj	*obj;

	if (!node)
		return ;
	for (int i = 0; i < depth; i++)
		printf("  ");
	printf("Node: ");
	if (!node->left && !node->right)
	{
		count = 0;
		obj = node->obj;
		while (obj)
		{
			count++;
			obj = obj->next;
		}
		printf("Leaf with %d objects\n", count);
	}
	else
	{
		printf("Internal\n");
		print_bvh(node->left, depth + 1);
		print_bvh(node->right, depth + 1);
	}
}

int	main(int argc, char *argv[])
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
	(void)argc;
	world.objects = NULL;
	paser(&world, argv[1]);
	world.obj_array = list_to_array(world.objects);
	world.bvh = build_bvh(world.obj_array.obj_array, 0, world.obj_array.count);
	raytracing(&world);
	printf("計算終わったよ\n");
	mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
	mlx_loop(world.mlx);
	return (0);
}
