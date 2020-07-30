/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:56:08 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/30 16:37:20 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		fill_obj_data(t_obj *ptr, int v, int f, int tri)
{
	
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
	while (line_ptr)
	{
		if ((*line_ptr)[0] == 'v')
			v_count++;
		if ((*line_ptr)[0] == 'f')
		{
			f_count++;
			tri_count = ft_char_count(*line_ptr, '0') - 2;
		}
		line_ptr++;
	}
	ptr->vertices = ft_memalloc(sizeof(float) * 3 * v_count);
	ptr->indices = ft_memalloc(sizeof(int) * 3 * tri_count);
	fill_obj_data(ptr, v_count, f_count, tri_count);
}

t_obj		*cut_lines(char *src)
{
	t_obj	*ptr;
	char	**lines;
	
	ptr = ft_memalloc(sizeof(t_obj));
	lines = ft_strsplit(src, '\n');
	obj_malloc(ptr, lines);
	ft_splitdel(&lines);
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

