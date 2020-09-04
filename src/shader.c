/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:12:21 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/04 11:50:05 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h" 

const char	*retrieve_shader_source(char *path)
{
	int			fd;
	struct stat	st;
	char		*src;
	int			ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		error_callback(-2, "Cannot open shader");
	if (stat(path, &st) == -1)
		error_callback(-3, "Cannot retrieve stats");
	if (!(src = ft_strnew(st.st_size)))
		error_callback(-4, "shader source allocation failed");
	if ((ret = read(fd, src, st.st_size)) == -1)
		error_callback(-5, "Cannot read shader");
	close(fd);
	return (src);
}

unsigned int	init_shader(char *path, GLenum shaderType)
{
	const char		*source;
	unsigned int	shader;
	int				success;
	char			infoLog[512];

	source = retrieve_shader_source(path);
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		error_callback(-6, "shader compilation failed");
		ft_putendl(infoLog);
	}

	return (shader);
}

unsigned int    init_shader_program()
{
	int				success;
	char			infoLog[512];
	unsigned int	shaderProgram;
    unsigned int	shaders[2];

	shaders[0] = init_shader("src/vertex.glsl", GL_VERTEX_SHADER);
	shaders[1] = init_shader("src/fragment.glsl", GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, shaders[0]);
	glAttachShader(shaderProgram, shaders[1]);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		error_callback(-7, "shader program compilation failed");
		ft_putendl(infoLog);
	}
	glDeleteShader(shaders[0]);
	glDeleteShader(shaders[1]);
	return (shaderProgram);
}
