/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:48:23 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/14 14:54:02 by mcm1k            ###   ########.fr       */
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
	vec.x = (max.x + min.x) / 2.0;
	vec.y = (max.y + min.y) / 2.0;
	vec.z = (max.z + min.z) / 2.0;
	vec.w = 1.0;
	
	return (vec);
}

void	move_to_center(t_obj *ptr)
{
	int		i;
	t_vec	center;

	i = 0;
	center = init_center(*ptr);
	while (i < (ptr->vertices_number / 3) * 5)
	{
		ptr->data[i + 0] -= center.x;
		ptr->data[i + 1] -= center.y;
		ptr->data[i + 2] -= center.z;
		i+=5;
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

void	normalize(t_obj *ptr)
{
	int		i;
	t_vec	size;

	i = 0;
    size = init_size(*ptr);
    while (i < (ptr->vertices_number / 3) * 5)
    {
        ptr->data[i + 0] *= size.x;
        ptr->data[i + 1] *= size.y;
        ptr->data[i + 2] *= size.z;
        i+=5;
    }
}
