/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
/*   Updated: 2025/05/16 22:53:11 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// t_camera	*make_camera(t_vec pos, t_vec dir, double fov, int width)
// {
// 	t_camera	*camera;

// 	camera = (t_camera *)malloc(sizeof(t_camera));
// 	if (camera == NULL)
// 		return (NULL);
// 	camera->pos = pos;
// 	camera->dir = vec_normalize(dir);
// 	camera->fov = fov;
// 	camera->sx = vec_normalize(vec_init(1, 0, -(camera->dir.x
// 					/ camera->dir.z)));
// 	camera->sy = vec_normalize(vec_cross(camera->dir, camera->sx));
// 	camera->view = vec_mult(camera->dir, (width / 2) / tan((fov / 2) * (3.14
// 					/ 180)));
// 	return (camera);
// }

void	make_camera(char **tokenlist, t_world *world)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return ;
	camera->pos = token_to_vec(tokenlist[1]);
	camera->dir = vec_normalize(token_to_vec(tokenlist[2]));
	camera->fov = ft_atof(tokenlist[3]);
	camera->sx = vec_normalize(vec_init(1, 0, -(camera->dir.x
					/ camera->dir.z)));
	camera->sy = vec_normalize(vec_cross(camera->dir, camera->sx));
	camera->view = vec_mult(camera->dir, (world->screen_width / 2)
			/ tan((camera->fov / 2) * (3.14 / 180)));
	world->cameras = camera;
}
