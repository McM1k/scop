/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:00:37 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/21 16:51:54 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

vec4	rotate(vec4 vec, vec4 axis, double angle)
{
	vec4	new_vec;
	double co;
	double si;
	co = cos(angle);
	si = sin(angle);
	new_vec.x = 
		(co + axis.x * axis.x * (1 - co)) * vec.x +
		(axis.x * axis.y * (1 - co) - axis.z * si) * vec.y +
		(axis.x * axis.z * (1 - co) + axis.y * si) * vec.z;
	new_vec.y = 
		(axis.x * axis.y * (1 - co) + axis.z * si) * vec.x +
		(co + axis.y * axis.y * (1 - co)) * vec.y +
		(axis.y * axis.z * (1 - co) - axis.x * si) * vec.z;
	new_vec.z = 
		(axis.x * axis.z * (1 - co) - axis.y * si) * vec.x +
		(axis.y * axis.z * (1 - co) + axis.x * si) * vec.y +
		(co + axis.z * axis.z * (1 - co)) * vec.z;
	new_vec.w = vec.w;
	return (new_vec);
}

vec4	translate(vec4 vec, vec4 trans)
{
	vec4	new_vec;

	new_vec.x = vec.x + trans.x * vec.w;
	new_vec.y = vec.y + trans.y * vec.w;
	new_vec.z = vec.z + trans.z * vec.w;
	new_vec.w = vec.w;
	return (new_vec);
}

vec4	scale(vec4 vec, vec4 scale)
{
	vec4	new_vec;

	new_vec.x = scale.x * vec.x;
	new_vec.y = scale.y * vec.y;
	new_vec.z = scale.z * vec.z;
	new_vec.w = vec.w;

	return (new_vec);
}
