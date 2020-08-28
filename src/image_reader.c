/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:34:05 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/28 14:59:09 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
__attribute__((unused))
void		rbg_to_rgb(t_bmp *ptr, int size)
{
	int		i;
	unsigned char	tmp;
	
	i = 0;
	while (i < size)
	{
		tmp = ptr->image[i+1];
		ptr->image[i+1] = ptr->image[i + 2];
		ptr->image[i+2] = tmp;
		i+=3;
	}
}

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
	size = bmp.biWidth * bmp.biHeight * bmp.biBitCount / 8;
	ft_putnbr((int)bmp.biBitCount);
	bmp.image = ft_memalloc(size);
	if ((ret = read(fd, bmp.image, size)) == -1)
		return (NULL);
//	bgr_to_rgb(&bmp, size);
	if (close(fd) == -1)
		return (NULL);
	ptr = ft_memalloc(sizeof(t_bmp));
	*ptr = bmp;
	return (ptr);
}
