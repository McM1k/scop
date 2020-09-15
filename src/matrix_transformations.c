/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:24:34 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 14:40:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	translate(t_vec t)
{
	t_mat	mat;

	mat.col[0].x = 1;
	mat.col[0].y = 0;
	mat.col[0].z = 0;
	mat.col[0].w = 0;
	mat.col[1].x = 0;
	mat.col[1].y = 1;
	mat.col[1].z = 0;
	mat.col[1].w = 0;
	mat.col[2].x = 0;
	mat.col[2].y = 0;
	mat.col[2].z = 1;
	mat.col[2].w = 0;
	mat.col[3].x = t.x;
	mat.col[3].y = t.y;
	mat.col[3].z = t.z;
	mat.col[3].w = 1;
	return (mat);
}

t_mat	scale(t_vec s)
{
	t_mat	mat;

	mat.col[0].x = s.x;
	mat.col[0].y = 0;
	mat.col[0].z = 0;
	mat.col[0].w = 0;
	mat.col[1].x = 0;
	mat.col[1].y = s.y;
	mat.col[1].z = 0;
	mat.col[1].w = 0;
	mat.col[2].x = 0;
	mat.col[2].y = 0;
	mat.col[2].z = s.z;
	mat.col[2].w = 0;
	mat.col[3].x = 0;
	mat.col[3].y = 0;
	mat.col[3].z = 0;
	mat.col[3].w = 1;
	return (mat);
}

t_mat	rotate(t_vec r, float angle)
{
	float	co;
	float	si;
	t_mat	mat;

	co = cosf(angle);
	si = sinf(angle);
	mat.col[0].x = r.x * r.x * (1 - co) + co;
	mat.col[0].y = r.x * r.y * (1 - co) + r.z * si;
	mat.col[0].z = r.x * r.z * (1 - co) - r.y * si;
	mat.col[0].w = 0;
	mat.col[1].x = r.y * r.x * (1 - co) - r.z * si;
	mat.col[1].y = r.y * r.y * (1 - co) + co;
	mat.col[1].z = r.y * r.z * (1 - co) + r.x * si;
	mat.col[1].w = 0;
	mat.col[2].x = r.z * r.x * (1 - co) + r.y * si;
	mat.col[2].y = r.z * r.y * (1 - co) - r.x * si;
	mat.col[2].z = r.z * r.z * (1 - co) + co;
	mat.col[2].w = 0;
	mat.col[3].x = 0;
	mat.col[3].y = 0;
	mat.col[3].z = 0;
	mat.col[3].w = 1;
	return (mat);
}

t_mat	identity(void)
{
	t_mat	mat;

	mat.col[0].x = 1;
	mat.col[0].y = 0;
	mat.col[0].z = 0;
	mat.col[0].w = 0;
	mat.col[1].x = 0;
	mat.col[1].y = 1;
	mat.col[1].z = 0;
	mat.col[1].w = 0;
	mat.col[2].x = 0;
	mat.col[2].y = 0;
	mat.col[2].z = 1;
	mat.col[2].w = 0;
	mat.col[3].x = 0;
	mat.col[3].y = 0;
	mat.col[3].z = 0;
	mat.col[3].w = 1;
	return (mat);
}
