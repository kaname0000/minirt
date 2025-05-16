/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:42:03 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:44:14 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

void	print_color(t_color color)
{
	printf("r = %f,g = %f,b = %f\n", color.red, color.green, color.blue);
}
