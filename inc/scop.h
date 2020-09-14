/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/14 12:37:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOP_H__
# define __SCOP_H__

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
	float			*data;
	float			*vertices;
	unsigned int	*indices;
	int				vertices_number;
	int				triangles;
	int				smooth;
}					t_obj;

typedef struct		  __attribute__((packed)) s_bmph
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
}					t_bmph;

typedef struct		s_texture
{
	t_bmph			header;
	unsigned char	*image;
	unsigned int	tex_nb;
}					t_texture;


//window.c
GLFWwindow		*init_window();

//events.c
void	framebuffer_size_callback(GLFWwindow *window, int width, int height);
void	error_callback(int error, const char *description);
void	key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
t_vec	move_view(t_vec cam_pos, GLFWwindow *window);
int		change_tex(int tex_mode, GLFWwindow *window);

//shader.c
unsigned int	init_shader_program();

//image_reader.c
t_texture		*read_bmp(char *path);

//obj_reader.c
t_obj			*get_obj(char *path);

//matrix_transformations.c
t_mat			rotate(t_vec r, float angle);
t_mat			translate(t_vec t);
t_mat			scale(t_vec s);
t_mat			identity(void);

//matrix_mvp.c
t_mat			get_model_matrix(t_mat t, t_mat r, t_mat s);
t_mat			get_view_matrix(t_mat t, t_vec axis, float angle, t_mat s);
t_mat			get_perspective_matrix(float width, float height, float fov);
t_mat			get_mvp_matrix(t_mat m, t_mat v, t_mat p);

//matrix_operations.c
t_vec			multiply_mat_vec(t_mat m, t_vec v);
t_mat			multiply_mat_mat(t_mat m1, t_mat m2);

//matrix_rev.c
t_mat			rev_mirror(t_mat m);
t_mat			rev_s(t_mat s);
t_mat			rev_t(t_mat t);

//matrix_utils.c
void			get_vec_as_tab(t_vec v, float *t);
void			get_mat_as_tab(t_mat m, float *t);
t_vec			set_vec(float x, float y, float z, float w);

//obj_init.c
void			move_to_center(t_obj *ptr);
void			normalize(t_obj *ptr);
t_vec			init_size(t_obj obj);
t_vec			init_center(t_obj obj);

//utils.c
t_vec			get_mins(t_obj obj);
t_vec			get_maxs(t_obj obj);

//textures.c
void			get_obj_data(t_obj *ptr);
void			init_tex(unsigned int shaderProgram);

//loop.c
t_vec			update_mix_values(t_vec mix, int mode);

//init.c
unsigned int	init_vao(t_obj *obj);
#endif
