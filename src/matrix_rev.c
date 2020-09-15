/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:05:16 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 14:33:59 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	rev_mirror(t_mat m)
{
	t_mat n;

	n.col[0].x = m.col[0].x;
	n.col[0].y = m.col[1].x;
	n.col[0].z = m.col[2].x;
	n.col[0].w = m.col[3].x;
	n.col[1].x = m.col[0].y;
	n.col[1].y = m.col[1].y;
	n.col[1].z = m.col[2].y;
	n.col[1].w = m.col[3].y;
	n.col[2].x = m.col[0].z;
	n.col[2].y = m.col[1].z;
	n.col[2].z = m.col[2].z;
	n.col[2].w = m.col[3].z;
	n.col[3].x = m.col[0].w;
	n.col[3].y = m.col[1].w;
	n.col[3].z = m.col[2].w;
	n.col[3].w = m.col[3].w;
	return (n);
}

t_mat	rev_s(t_mat s)
{
	s.col[0].x = 1 / s.col[0].x;
	s.col[1].y = 1 / s.col[1].y;
	s.col[2].z = 1 / s.col[2].z;
	return (s);
}

t_mat	rev_t(t_mat t)
{
	t.col[3].x *= -1;
	t.col[3].y *= -1;
	t.col[3].z *= -1;
	return (t);
}
