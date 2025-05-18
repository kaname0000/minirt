/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:02:54 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 20:00:15 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_aabb	surrounding_centroid_box(t_obj **objects, int start, int end)
{
	t_aabb	box;
	int		i;

	box = get_aabb(objects[start]);
	for (i = start + 1; i < end; i++)
		box = surrounding_box(box, get_aabb(objects[i]));
	return (box);
}

int	choose_longest_axis(t_aabb box)
{
	t_vec	size;

	size = vec_sub(box.max, box.min);
	if (size.x > size.y && size.x > size.z)
		return (0);
	else if (size.y > size.z)
		return (1);
	else
		return (2);
}

t_bvh_node	*build_bvh(t_obj **objects, int start, int end)
{
	t_bvh_node	*node;
	int			count;
	int			axis;
	int			mid;

	count = end - start;
	if (count <= 0)
		return (NULL);
	node = malloc(sizeof(t_bvh_node));
	if (!node)
		return (NULL);
	if (count <= 2)
	{
		for (int i = start; i < end - 1; i++)
			objects[i]->next = objects[i + 1];
		objects[end - 1]->next = NULL;
		node->obj = objects[start];
		node->left = NULL;
		node->right = NULL;
		node->box = get_aabb(objects[start]);
		for (int i = start + 1; i < end; i++)
			node->box = surrounding_box(node->box, get_aabb(objects[i]));
		return (node);
	}
	axis = choose_longest_axis(surrounding_centroid_box(objects, start, end));
	sort_obj(objects, start, end, axis);
	mid = start + count / 2;
	node->left = build_bvh(objects, start, mid);
	node->right = build_bvh(objects, mid, end);
	node->obj = NULL;
	node->box = surrounding_box(node->left->box, node->right->box);
	return (node);
}
