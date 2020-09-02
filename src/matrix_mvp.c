/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:21:53 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/02 16:38:18 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	get_model_matrix(t_mat t, t_mat r, t_mat s)
{
	t_mat	m;

	m = identity();
	m = multiply_mat_mat(s, m);
	m = multiply_mat_mat(r, m);
	m = multiply_mat_mat(t, m);
	return (m);
}

t_mat	get_view_matrix(t_mat t, t_vec axis, float angle, t_mat s)
{
	t_mat	v;

	v = identity();
	v = multiply_mat_mat(rev_s(s), v);
	v = multiply_mat_mat(rotate(axis, -angle), v);
	v = multiply_mat_mat(rev_t(t), v);
	return (v);
}

t_mat	get_perspective_matrix(float width, float height, float fov)
{
	t_mat	p;
	float	tanHalfFOV;
	float	near;
	float	far;

	near = 0.1;
	far = 100.0;
	tanHalfFOV = tanf((fov / 2.0) * M_PI / 180.0);
	p.col[0].x = 1.0 / (tanHalfFOV * width/height);
	p.col[0].y = 0.0;
	p.col[0].z = 0.0;
	p.col[0].w = 0.0;
	p.col[1].x = 0.0;
	p.col[1].y = 1.0 / tanHalfFOV;
	p.col[1].z = 0.0;
	p.col[1].w = 0.0;
	p.col[2].x = 0.0;
	p.col[2].y = 0.0;
	p.col[2].z = - (far + near) / (far - near);
	p.col[2].w = -1.0;
	p.col[3].x = 0.0;
	p.col[3].y = 0.0;
	p.col[3].z = -(2 * near * far) / (far - near);
	p.col[3].w = 0.0;
	return (p);
}

t_mat	get_mvp_matrix(t_mat m, t_mat v, t_mat p)
{
	t_mat	mvp;

	mvp = identity();
	mvp = multiply_mat_mat(m, mvp);
	mvp = multiply_mat_mat(v, mvp);
	mvp = multiply_mat_mat(p, mvp);
	return (mvp);
}
