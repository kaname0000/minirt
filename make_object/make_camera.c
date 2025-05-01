/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 20:44:12 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_camera	*make_camera(t_vec pos, t_vec dir, double fov, int width)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera->pos = pos;
	camera->dir = dir;
	camera->fov = fov;
	camera->sx = vec_normalize(vec_init(1, 0, -(dir.x / dir.z)));
	camera->sy = vec_normalize(vec_cross(dir, camera->sx));
	camera->view = vec_mult(dir, (width / 2) / tan((fov / 2) * (3.14 / 180)));
	return (camera);
}
