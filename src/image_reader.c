/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:34:05 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/13 15:03:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bmp		*read_bmp(char *path)
{
	t_bmp	bmp;
	int		fd;
	char	buf_head[54];
	int		head_size;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf_head, 54)) == -1 || (ret < 54))
		return (NULL);
	if (!get_bmp_info(buf_head, &bmp))
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (&bmp);
}

t_bmp		*get_bmp_info(char *header, t_bmp *bmp)
{
	ft_memcpy(*bmp, header, 54);
	if (bmp.bfType[0] != 'B' && bmp.bfType[1] != 'M')
	{
		error_callback(-101, "not a BM bitmap image");
		return (NULL);
	}
	if (bmp.bfOffBits != 54)
	{
		error_callback(-102, "bad offBit");
		return (NULL);
	}
	return (bmp);
}
