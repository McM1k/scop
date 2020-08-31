/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:19:09 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/31 17:19:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat   minus_matrix(t_mat p)
{
    t_mat   m;
    int    i;

    i =0;
    while (i < 4)
    {
        m.col[i].x = - p.col[i].x;
        m.col[i].y = - p.col[i].y;
        m.col[i].z = - p.col[i].z;
        i++;
    }
    return (m);
}

t_mat   div_matrix(t_mat m)
{
    t_mat   d;
    int     i;

    i = 0;
    while (i < 4)
    {
        d.col[i].x = 1 / m.col[i].x;
        d.col[i].y = 1 / m.col[i].y;
        d.col[i].z = 1 / m.col[i].z;
        i++;
    }
    return (d);
}

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
