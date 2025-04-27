/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:27:43 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:52:47 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	*make_sphere(t_vec pos, double dia, t_color color)
{
	t_obj		*obj;
	t_sphere	sphere;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	sphere.dia = dia;
	sphere.pos = pos;
	sphere.color = color;
	obj->type = SPHERE;
	obj->u_object.sphere = sphere;
	obj->next = NULL;
	return (obj);
}
