/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:14:03 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 17:32:56 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		new_tex(char *path, unsigned int tx_id, GLenum tx_enum)
{
	t_texture	*ptr;

	ptr = read_bmp(path);
	glActiveTexture(tx_enum);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
					GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, tx_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ptr->header.biWidth,
					ptr->header.biHeight, 0, GL_BGR,
					GL_UNSIGNED_BYTE, ptr->image);
	glGenerateMipmap(GL_TEXTURE_2D);
	ft_memdel((void **)&(ptr->image));
	ft_memdel((void **)&ptr);
}

void		init_tex(unsigned int shader_program)
{
	unsigned int texs[3];

	glGenTextures(3, texs);
	glUseProgram(shader_program);
	new_tex("res/unicorn.bmp", texs[0], GL_TEXTURE0);
	new_tex("res/ivy.bmp", texs[1], GL_TEXTURE1);
	new_tex("res/vivlevan.bmp", texs[2], GL_TEXTURE2);
	glUniform1i(glGetUniformLocation(shader_program, "tex1"), 0);
	glUniform1i(glGetUniformLocation(shader_program, "tex2"), 1);
	glUniform1i(glGetUniformLocation(shader_program, "tex3"), 2);
	glEnable(GL_DEPTH_TEST);
}

void		scale_vertices(t_obj *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ptr->vertices_number)
	{
		ptr->data[j + 0] = ptr->vertices[i + 0];
		ptr->data[j + 1] = ptr->vertices[i + 1];
		ptr->data[j + 2] = ptr->vertices[i + 2];
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
		ptr->data[i + 4] = ((ptr->data[i + 1] * 2 / size) - 1) * 3;
		ptr->data[i + 3] = ((ptr->data[i + 2] * 2 / size) - 1) * 3;
		i += 5;
	}
}

void		get_obj_data(t_obj *ptr)
{
	ptr->data = ft_memalloc(sizeof(float) * 5 * (ptr->vertices_number / 3));
	scale_vertices(ptr);
	scale_coords(ptr);
}
