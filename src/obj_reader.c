/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:56:08 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/29 16:51:29 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_obj		*parse(char *src)
{
	t_obj	*ptr;
	
	ft_memalloc(sizeof(t_obj));
	

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
	return (parse(src));
}

