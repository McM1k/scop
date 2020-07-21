/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/21 16:52:16 by gboudrie         ###   ########.fr       */
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

typedef struct		  __attribute__((packed)) s_bmp
{
	char			bfType1;
	char			bfType2;
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
	unsigned char	*image __attribute__((aligned(8)));
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
t_bmp			*read_bmp(char *path);

//transform.c
vec4			rotate(vec4 vec, vec4 axis, double angle);
vec4			translate(vec4 vec, vec4 trans);
vec4			scale(vec4 vec, vec4 scale);

#endif
