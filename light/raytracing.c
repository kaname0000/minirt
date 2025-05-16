/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:52:17 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	raytracing(t_world *world)
{
	int		i;
	int		j;
	int		color;
	t_color	zero_color;
	t_color	diffuse;
	t_color	ambient;
	t_color	specular;
	t_insec	insec;
	t_ray	ray;

	i = 0;
	zero_color = color_init(0, 0, 0);
	ray.start = world->cameras->pos;
	while (i < world->screen_width)
	{
		j = 0;
		while (j < world->screen_height)
		{
			ray.dir = ray_dir(world, world->cameras, i, j);
			insec = trace_nearest(ray, world->objects);
			ambient = ambient_light(world->ambient, insec.color, insec.flag);
			in_shadow(&insec, world->objects, world->lights);
			diffuse = diffuse_reflection(world->lights, insec, insec.type);
			specular = specular_reflection(ray, insec, world->lights);
			color = cal_color(ambient, diffuse, specular);
			my_mlx_pixel_put(world, i, j, color);
			j++;
		}
		i++;
	}
}
