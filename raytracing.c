/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:43 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 19:20:07 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raytracing(t_world *world)
{
	int		i;
	int		j;
	int		color;
	t_vec	camera;
	t_vec	sphere;
	t_vec	light;
	t_vec	intersection;
	double	diffuse;
	double	ambient;
	double	specular;
	t_color	color1;

	camera = vec_init(0, 0, -5);
	sphere = vec_init(0, 0, 5);
	light = vec_init(-5, -5, -5);
	color1 = color_init(100.0, 100.0, 100.0);
	i = 0;
	while (i < world->screen_width)
	{
		j = 0;
		while (j < world->screen_height)
		{
			intersection = hit_intersection(sphere, camera, vec_init(((double)i
							/ world->screen_width) * 2.0 - 1.0, ((double)j
							/ world->screen_height) * 2.0 - 1.0, 0), 1);
			diffuse = diffuse_reflection(light, intersection, sphere);
			ambient = ambient_light(intersection, 0.01, 0.1);
			specular = specular_reflection(camera, intersection, light, sphere);
			color = apply_diffuse_color(diffuse + ambient + specular, color1);
			my_mlx_pixel_put(world, i, j, color);
			j++;
		}
		i++;
	}
}
