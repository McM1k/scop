/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:34:05 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/20 12:57:32 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bmp		*get_bmp_info(char *header, t_bmp *bmp)
{

	ft_memcpy(bmp, header, 54);

	ft_putstr("type: ");
	ft_putchar(bmp->bfType[0]);
	ft_putchar(bmp->bfType[1]);
	ft_putchar('\n');
	ft_putstr("bfSize: ");
	ft_putnbr((bmp->bfSize));
	ft_putchar('\n');
	ft_putstr("bfReserved1: ");
	ft_putnbr((int)(bmp->bfReserved1));
	ft_putchar('\n');
	ft_putstr("bfReserved2: ");
	ft_putnbr((int)(bmp->bfReserved2));
	ft_putchar('\n');
	ft_putstr("offbits: ");
	ft_putnbr(bmp->bfOffBits);
	ft_putchar('\n');
	
	ft_putstr("biSize: ");
	ft_putnbr((bmp->biSize));
	ft_putchar('\n');
	ft_putstr("width: ");
	ft_putnbr(bmp->biWidth);
	ft_putchar('\n');
	ft_putstr("height: ");
	ft_putnbr(bmp->biHeight);
	ft_putchar('\n');
	ft_putstr("biPlanes: ");
	ft_putnbr((int)(bmp->biPlanes));
	ft_putchar('\n');
	ft_putstr("pixSize: ");
	ft_putnbr((int)(bmp->biBitCount));
	ft_putchar('\n');
	ft_putstr("biCompression: ");
	ft_putnbr((int)(bmp->biCompression));
	ft_putchar('\n');
	ft_putstr("biSizeImage: ");
	ft_putnbr((int)(bmp->biSizeImage));
	ft_putchar('\n');
	ft_putstr("biXPelsPerMeter: ");
	ft_putnbr((int)(bmp->biXPelsPerMeter));
	ft_putchar('\n');
	ft_putstr("biYPelsPerMeter: ");
	ft_putnbr((int)(bmp->biYPelsPerMeter));
	ft_putchar('\n');
	ft_putstr("biClrUsed: ");
	ft_putnbr((int)(bmp->biClrUsed));
	ft_putchar('\n');
	ft_putstr("biClrImportant: ");
	ft_putnbr((int)(bmp->biClrImportant));
	ft_putchar('\n');


	if (bmp->bfType[0] != 'B' && bmp->bfType[1] != 'M')
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

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf_head, 54)) == -1 || (ret < 54))
		return (NULL);
	if (!get_bmp_info(buf_head, &bmp))
		return (NULL);
	size = bmp.biWidth * bmp.biHeight * bmp.biBitCount;
	bmp.image = ft_memalloc(size + 1);
	if ((ret = read(fd, bmp.image, size)) == -1)
	  return (NULL);
	bmp.image[size] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (ft_memalloc(sizeof(t_bmp)));
}
