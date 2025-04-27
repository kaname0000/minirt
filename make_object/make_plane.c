/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:52:51 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:54:38 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	*make_plane(t_vec pos, t_vec normal, t_color color)
{
	t_obj	*obj;
	t_plane	plane;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	plane.pos = pos;
	plane.normal = normal;
	plane.color = color;
	obj->type = PLANE;
	obj->u_object.plane = plane;
	obj->next = NULL;
	return (obj);
}
