/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:56:08 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/28 16:53:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_obj		*get_obj(char *path)
{
	int		fd;
	t_obj	*ptr;


	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	ptr = ft_memalloc(sizeof(t_obj));
	*ptr = parse(fd);
	if (close(fd) == -1)
		return (NULL);
	return (ptr);
}
