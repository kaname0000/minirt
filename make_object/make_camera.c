/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 19:18:50 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_camera	*make_camera(t_vec pos, t_vec dir, double fob)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return (NULL);
	camera->pos = pos;
	camera->dir = dir;
	camera->fov = fob;
	return (camera);
}
