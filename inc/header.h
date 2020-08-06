/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/06 14:04:46 by gboudrie         ###   ########.fr       */
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
# include <stdlib.h>

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec;

typedef struct		s_mat
{
	t_vec			col[4];
}					t_mat;

typedef struct		s_obj
{
	float			*vertices;
	unsigned int	*indices;
	int				vertices_number;
	int				triangles;
	int				smooth;
}					t_obj;

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

//obj_reader.c
t_obj			*get_obj(char *path);

//matrix_transformations.c
t_mat			rotate(t_vec r, float angle);
t_mat			translate(t_vec t);
t_mat			scale(t_vec s);
t_mat			identity(void);

//matrix_operations.c
t_vec			multiply_mat_vec(t_mat m, t_vec v);
t_mat			multiply_mat_mat(t_mat m1, t_mat m2);

//matrix_utils.c
void			get_vec_as_tab(t_vec v, float *t);
void			get_mat_as_tab(t_mat m, float *t);
t_vec			set_vec(float x, float y, float z, float w);

#endif
