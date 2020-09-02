/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:48:23 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/02 18:12:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec	init_center(t_obj obj)
{
	t_vec vec;
	t_vec min;
	t_vec max;

	min = get_mins(obj);
	max = get_maxs(obj);
	vec.x = (max.x - min.x) / 2.0;
	vec.y = (max.y - min.y) / 2.0;
	vec.z = (max.z - min.z) / 2.0;
	vec.w = 1.0;
	
	return (vec);
}

void	move_to_center(t_obj *ptr)
{
	int		i;
	t_vec	center;

	i = 0;
	center = init_center(*ptr);
	while (i < ptr->vertices_number)
	{
		ptr->vertices[i + 0] -= center.x;
		ptr->vertices[i + 1] -= center.y;
		ptr->vertices[i + 2] -= center.z;
		i+=3;
	}
}

t_vec	init_size(t_obj obj)
{
	t_vec vec;
	t_vec min;
	t_vec max;

	min = get_mins(obj);
	max = get_maxs(obj);
	vec.x = max.x - min.x;
	vec.y = max.y - min.y;
	vec.z = max.z - min.z;
	vec.w = vec.x;
	if (vec.x < vec.y)
	{
		vec.w = vec.y;
		if (vec.y < vec.z)
			vec.w = vec.z;
	}
	vec.z = 1/vec.w;
	vec.y = 1/vec.w;
	vec.x = 1/vec.w;
	vec.w = 1;
	return (vec);
}