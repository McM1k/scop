/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:12 by gboudrie          #+#    #+#             */
/*   Updated: 2020/08/25 16:35:28 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
	GLFWwindow	*window;
	window = init_window();
	if (!window) 
		return(-1);
	/*
	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};  
*/
	t_obj	*obj = get_obj("res/42.obj");

	int i = 0;
	while (i < obj->triangles * 3)
	{
		ft_putnbr(obj->indices[i]);
		ft_putchar(' ');
		i++;
		if (i % 3 == 0)
			ft_putendl("");
	}

	t_bmp *bmp = read_bmp("res/vivlevan.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	unsigned int texture;
	glGenTextures(1, &texture);  
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp->biWidth, bmp->biHeight,
				 0, GL_RGB, GL_UNSIGNED_BYTE, bmp->image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
	t_vec vec;
	t_vec sca;
	t_mat mat;
	vec = set_vec(0.0, 1.0, 0.0, 0.0);
	sca = init_size(*obj);
	float	trans[16];

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	unsigned int VBO;
    glGenBuffers(1, &VBO);
    unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * obj->vertices_number,
				 obj->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 3 * obj->triangles,
				 obj->indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
						  (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int shaderProgram = init_shader_program();
	
	while(!glfwWindowShouldClose(window))
    {
		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		mat = translate(init_axis(*obj));
		mat = multiply_mat_mat(mat, rotate(vec, (float)glfwGetTime()));
		mat = multiply_mat_mat(mat, scale(sca));
		get_mat_as_tab(mat, trans);
		unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, trans);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, obj->triangles * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);		
		glfwSwapBuffers(window);
        glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
	ft_memdel((void **)&(bmp->image));
	ft_memdel((void **)&bmp);
	ft_memdel((void **)&(obj->vertices));
	ft_memdel((void **)&(obj->indices));
	ft_memdel((void **)&obj);
    glfwTerminate();
    return(0);
}
