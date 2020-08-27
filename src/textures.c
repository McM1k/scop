/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:14:03 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/27 18:28:26 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		scale_vertices(t_obj *ptr)
{
	int		i;
	int		j;
	t_vec	size;

	i = 0;
	j = 0;
	size = init_size(*ptr);
	while (i < ptr->vertices_number)
	{
		ptr->data[j + 0] = ptr->vertices[i + 0] * size.x;
		ptr->data[j + 1] = ptr->vertices[i + 1] * size.x;
		ptr->data[j + 2] = ptr->vertices[i + 2] * size.x;
		i += 3;
		j += 5;
	}
}

void		scale_coords(t_obj *ptr)
{
	int		i;
	float	size;
	t_vec	min;
	t_vec	max;

	i = 0;
	min = get_mins(*ptr);
	max = get_maxs(*ptr);
	if ((max.y - min.y) > (max.z - min.z))
		size = max.y - min.y;
	else
		size = max.z - min.z;
	while (i < 5 * (ptr->vertices_number / 3))
	{
		ptr->data[i + 4] = ((ptr->data[i + 1] * 2 / size) - 1) * 10;
		ptr->data[i + 3] = ((ptr->data[i + 2] * 2 / size) - 1) * 10;
		i += 5;
	}

}

void		get_obj_data(t_obj *ptr)
{
	ptr->data = ft_memalloc(sizeof(float) * 5 * (ptr->vertices_number / 3));
	scale_vertices(ptr);
	scale_coords(ptr);
}
