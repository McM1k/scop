/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:48:23 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/31 17:26:27 by gboudrie         ###   ########.fr       */
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
	vec.x = -(max.x - min.x) / 2;
	vec.y = -(max.y - min.y) / 2;
	vec.z = -(max.z - min.z) / 2;
	vec.w = 0.0;

	vec.x = -0.0;
	vec.y = -0.0;
	vec.z = -0.3;
	
	return (vec);
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
