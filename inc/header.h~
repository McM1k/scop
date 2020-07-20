/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/13 14:11:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER_H__
# define __HEADER_H__

# include <glad.h>
# include <GLFW/glfw3.h>
# include <libft/libft.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct		s_bmp
{
	char			bfType[2];
	int				bfSize;
	short int		bfReserved1;
	short int		bfReserved2;
	int				bfOffBits; // +10bits
	int				biSize;
	int				biWidth; // +18bits
	int				biHeight; // +22bits
	short int		biPlanes;
	short int		biBitCount; // +28bits
	int				biCompression;
	int				biSizeImage;
	int				biXPelsPerMeter;
	int				biYPelsPerMeter;
	int				biClrUsed;
	int				biClrImportant;
  char *image;
}					t_bmp;


//window.c
GLFWwindow		*init_window();

//events.c
void	framebuffer_size_callback(GLFWwindow *window, int width, int height);
void	error_callback(int error, const char *description);
void	key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

//shader.c
unsigned int	init_shader_program();

//image_reader.c
unsigned char	*get_data_from_bmp(char *path);

#endif
