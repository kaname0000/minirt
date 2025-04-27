/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:46 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 18:58:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	*make_cylinder(t_vec pos, double dia, double height, t_color color)
{
	t_obj		*obj;
	t_cylinder	cylinder;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	cylinder.pos = pos;
	cylinder.dia = dia;
	cylinder.height = height;
	cylinder.color = color;
	obj->type = CYLINDER;
	obj->u_object.cylinder = cylinder;
	obj->next = NULL;
	return (obj);
}
