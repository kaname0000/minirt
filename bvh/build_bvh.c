/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:02:54 by okaname           #+#    #+#             */
/*   Updated: 2025/05/21 16:09:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_aabb combine_aabbs(t_obj **objects, int start, int end) {
    t_aabb box = get_aabb(objects[start]);
    for (int i = start + 1; i < end; i++) {
        box = surrounding_box(box, get_aabb(objects[i]));
    }
    return box;
}


float surface_area(t_aabb box) {
    t_vec size = vec_sub(box.max, box.min);
    return 2 * (size.x * size.y + size.y * size.z + size.z * size.x);
}

t_sah cal_sah(t_obj **objects, int start, int end) {
	t_sah sah;
	float best_cost = 1e30f;

	for (int axis = 0; axis < 3; axis++) {
		sort_obj(objects, start, end, axis);  // centroidでsort
		for (int i = start + 1; i < end; i++) {
			t_aabb left_box = combine_aabbs(objects, start, i);
			t_aabb right_box = combine_aabbs(objects, i, end);

			int n_left = i - start;
			int n_right = end - i;

			float cost = surface_area(left_box) * n_left +
						 surface_area(right_box) * n_right;

			if (cost < best_cost) {
				best_cost = cost;
				sah.best_axis = axis;
				sah.best_split = i;
			}
		}
	}
	return sah;
}


// t_aabb	surrounding_centroid_box(t_obj **objects, int start, int end)
// {
// 	t_aabb	box;
// 	int		i;

// 	box = objects[start]->box;
// 	for (i = start + 1; i < end; i++)
// 		box = surrounding_box(box, objects[i]->box);
// 	return (box);
// }

// int	choose_longest_axis(t_aabb box)
// {
// 	t_vec	size;

// 	size = vec_sub(box.max, box.min);
// 	if (size.x > size.y && size.x > size.z)
// 		return (0);
// 	else if (size.y > size.z)
// 		return (1);
// 	else
// 		return (2);
// }

t_bvh_node	*build_bvh(t_obj **objects, int start, int end)
{
	t_bvh_node	*node;
	int			count;
	t_sah sah;

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
	sah = cal_sah(objects, start, end);
	sort_obj(objects, start, end, sah.best_axis);
	node->left = build_bvh(objects, start, sah.best_split);
	node->right = build_bvh(objects, sah.best_split, end);
	node->obj = NULL;
	node->box = surrounding_box(node->left->box, node->right->box);
	return (node);
}
