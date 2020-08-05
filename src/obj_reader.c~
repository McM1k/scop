/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:56:08 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/04 16:32:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void		triangulate(t_obj *ptr, char **split, int *tri)
{
	int		f_size;

	f_size = 0;
	while (split[f_size])
		f_size++;
	while (f_size > 3)
	{
		ptr->indices[(*tri) + f_size - 3]
			= (unsigned int)ft_atoi(split[f_size - 3]);
		ptr->indices[(*tri) + f_size - 2]
			= (unsigned int)ft_atoi(split[f_size - 2]);  
		ptr->indices[(*tri) + f_size - 1]
			= (unsigned int)ft_atoi(split[f_size - 1]);
		f_size--;
		(*tri)+=3;
	}
}

void		fill_obj_data(t_obj *ptr, char **lines)
{
	int		i;
	char	**split;
	int		v;
	int		tri;

	i = 0;
	v = 0;
	tri = 0;
	while (lines[i])
	{
	split = ft_strsplit(lines[i], ' ');
		if (split[0][0] == 'v')
		{
			ptr->vertices[v] = strtof(split[1], NULL);
			ptr->vertices[v+1] = strtof(split[2], NULL);
			ptr->vertices[v+2] = strtof(split[3], NULL);
			v+=3;
		}
		else if (split[0][0] == 'f')
			triangulate(ptr, split, &tri);
		else if (split[0][0] == 's' && ft_strcmp(split[1], "off") == 0)
			ptr->smooth = 0;
		ft_splitdel((void **)split);
		i++;
	}
}

void		obj_malloc(t_obj *ptr, char **lines)
{
	char	**line_ptr;
	int		v_count;
	int		f_count;
	int		tri_count;

	line_ptr = lines;
	v_count = 0;
	f_count = 0;
	tri_count = 0;
	while (*line_ptr)
	{
		if ((*line_ptr)[0] == 'v')
			v_count++;
		if ((*line_ptr)[0] == 'f')
		{
			f_count++;
			tri_count += ft_char_count(*line_ptr, ' ') - 2;
		}
		line_ptr++;
	}
	ptr->triangles = tri_count;
	ptr->vertices = ft_memalloc(sizeof(float) * 3 * v_count);
	ptr->indices = ft_memalloc(sizeof(int) * 3 * tri_count);
	fill_obj_data(ptr, lines);
}

t_obj		*cut_lines(char *src)
{
	t_obj	*ptr;
	char	**lines;

	ptr = ft_memalloc(sizeof(t_obj));
	ptr->smooth = 1;
	lines = ft_strsplit(src, '\n');
	ft_memdel((void **)&src);
	obj_malloc(ptr, lines);
	ft_splitdel((void **)lines);
	return (ptr);
}

t_obj		*get_obj(char *path)
{
	int			fd;
	struct stat	st;
	char		*src;
	int			ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if (stat(path, &st) == -1)
		return (NULL);
	if (!(src = ft_strnew(st.st_size)))
		return (NULL);
	if ((ret = read(fd, src, st.st_size)) == -1)
		return (NULL);
	close(fd);
	return (cut_lines(src));
}
