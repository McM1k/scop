/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:12:21 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/09 16:23:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h" 

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
    unsigned int vertexShader = init_shader("src/vertex.glsl", GL_VERTEX_SHADER);
    unsigned int fragmentShader = init_shader("src/fragment.glsl", GL_FRAGMENT_SHADER);
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        error_callback(-7, "shader program compilation failed");
        ft_putendl(infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}
