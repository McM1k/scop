/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:32:47 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 14:44:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec	get_mins(t_obj obj)
{
	int		i;
	t_vec	vec;

	vec.x = obj.vertices[0];
	vec.y = obj.vertices[1];
	vec.z = obj.vertices[2];
	i = 3;
	while (i < obj.vertices_number)
	{
		if (vec.x > obj.vertices[i + 0])
			vec.x = obj.vertices[i + 0];
		if (vec.y > obj.vertices[i + 1])
			vec.y = obj.vertices[i + 1];
		if (vec.z > obj.vertices[i + 2])
			vec.z = obj.vertices[i + 2];
		i += 3;
	}
	return (vec);
}

t_vec	get_maxs(t_obj obj)
{
	int		i;
	t_vec	vec;

	vec.x = obj.vertices[0];
	vec.y = obj.vertices[1];
	vec.z = obj.vertices[2];
	i = 3;
	while (i < obj.vertices_number)
	{
		if (vec.x < obj.vertices[i + 0])
			vec.x = obj.vertices[i + 0];
		if (vec.y < obj.vertices[i + 1])
			vec.y = obj.vertices[i + 1];
		if (vec.z < obj.vertices[i + 2])
			vec.z = obj.vertices[i + 2];
		i += 3;
	}
	return (vec);
}
