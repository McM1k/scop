/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:22:47 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/23 11:27:20 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    get_vec_as_tab(t_vec v, float *t)
{
    t[0] = v.x;
    t[1] = v.y;
    t[2] = v.z;
    t[3] = v.w;
}

void    get_mat_as_tab(t_mat m, float *t)
{
    get_vec_as_tab(m.col[0], &(t[0]));
    get_vec_as_tab(m.col[1], &(t[4]));
    get_vec_as_tab(m.col[2], &(t[8]));
    get_vec_as_tab(m.col[3], &(t[12]));
}

t_vec	set_vec(float x, float y, float z, float w)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;

	return (vec);
}
