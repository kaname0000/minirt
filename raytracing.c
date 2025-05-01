/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 21:27:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raytracing(t_world *world)
{
	int		i;
	int		j;
	int		color;
	double	diffuse;
	double	ambient;
	double	specular;
	t_insec	insec;
	t_ray	ray;

	i = 0;
	ray.start = world->cameras->pos;
	while (i < world->screen_width)
	{
		j = 0;
		while (j < world->screen_height)
		{
			ray.dir = ray_dir(world, world->cameras, i, j);
			insec = trace_nearest(ray, world->objects);
			diffuse = diffuse_reflection(world->lights, insec);
			ambient = ambient_light(insec.flag, 0.01, 0.1);
			specular = specular_reflection(ray, insec, world->lights);
			color = apply_diffuse_color(diffuse + ambient + specular,
					insec.color);
			my_mlx_pixel_put(world, i, j, color);
			j++;
		}
		i++;
	}
}
