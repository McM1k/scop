/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:34:05 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/02 18:24:40 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_bmp		*get_bmp_info(char *header, t_bmp *bmp)
{

	ft_memcpy(bmp, header, 54);
	if (bmp->bfType1 != 'B' && bmp->bfType2 != 'M')
	{
		error_callback(-101, "not a BM bitmap image");
		return (NULL);
	}
	if (bmp->bfOffBits != 54)
	{
		error_callback(-102, "bad offBit");
		return (NULL);
	}
	return (bmp);
}

t_bmp		*read_bmp(char *path)
{
	t_bmp	bmp;
	int		fd;
	char	buf_head[54];
	int		size;
	int		ret;
	t_bmp	*ptr;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf_head, 54)) == -1 || (ret < 54))
		return (NULL);
	if (!get_bmp_info(buf_head, &bmp))
		return (NULL);
	size = (bmp.biWidth + 1) * (bmp.biHeight + 1) * bmp.biBitCount / 8;
	bmp.image = ft_memalloc(size);
	if ((ret = read(fd, bmp.image, size)) == -1)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	ptr = ft_memalloc(sizeof(t_bmp));
	*ptr = bmp;
	return (ptr);
}
