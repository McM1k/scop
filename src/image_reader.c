/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:34:05 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/03 18:20:21 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_bmph		*get_bmp_info(char *header, t_bmp *bmph)
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

t_texture	*read_bmp(char *path)
{
	t_texture	tx;
	int			fd;
	char		buf_head[54];
	int			size;
	int			ret;
	t_texture	*ptr;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf_head, 54)) == -1 || (ret < 54))
		return (NULL);
	if (!get_bmp_info(buf_head, &tx.header))
		return (NULL);
	size = (tx.header.biWidth + 1) * (tx.header.biHeight + 1) 
		* tx.header.biBitCount / 8;
	tx.image = ft_memalloc(size);
	if ((ret = read(fd, tx.image, size)) == -1)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	ptr = ft_memalloc(sizeof(t_texture));
	*ptr = tx;
	return (ptr);
}
