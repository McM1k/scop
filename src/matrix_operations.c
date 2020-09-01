/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:19:09 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/01 12:05:03 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec	multiply_mat_vec(t_mat m, t_vec v)
{
	t_vec	res;

	res.x = m.col[0].x * v.x
		+ m.col[1].x * v.y
		+ m.col[2].x * v.z
		+ m.col[3].x * v.w;
	res.y = m.col[0].y * v.x
		+ m.col[1].y * v.y
		+ m.col[2].y * v.z
		+ m.col[3].y * v.w;
	res.z = m.col[0].z * v.x
		+ m.col[1].z * v.y
		+ m.col[2].z * v.z
		+ m.col[3].z * v.w;
	res.w = m.col[0].w * v.x
		+ m.col[1].w * v.y
		+ m.col[2].w * v.z
		+ m.col[3].w * v.w;

	return (res);
}

t_mat	multiply_mat_mat(t_mat m1, t_mat m2)
{
	t_mat	res;
	int		i;

	i = 0;
	while (i < 4)
	{
		res.col[i] = multiply_mat_vec(m1, m2.col[i]);
		i++;
	}
	return (res);
}
