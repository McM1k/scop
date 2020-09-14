/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:12 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/12 23:09:56 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int     main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
   	GLFWwindow	*window;
	window = init_window();
	if (!window) 
		return(-1);
	t_obj	*obj;
	if (!(obj = get_obj(av[1])))
		return(-1);
	
	unsigned int shaderProgram;
	shaderProgram = init_shader_program();
	init_tex(shaderProgram);
	float	trans[16];
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,
		     sizeof(float) * 5 * (obj->vertices_number / 3),
		     obj->data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		     sizeof(unsigned int) * 3 * obj->triangles,
		     obj->indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
						  (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	t_vec vec;
	vec = set_vec(0.0, 1.0, 0.0, 0.0);
	t_mat	r, t_v;
	t_vec	cam_pos = set_vec(0.0, 0.0, 1.0, 1.0);
	t_mat	m, v, p;
	int		tex_mode;

	t_vec	mix;
	mix = set_vec(1.0, 0.0, 0.0, 0.0);
	tex_mode = 1;
	while(!glfwWindowShouldClose(window))
    {
		tex_mode = change_tex(tex_mode, window);
		mix = update_mix_values(mix, tex_mode);
		r = rotate(vec, (float)glfwGetTime());
		m = get_model_matrix(identity(), r, identity());
		cam_pos = move_view(cam_pos, window);
		t_v = translate(cam_pos);
		v = get_view_matrix(t_v, vec, 0.0, identity());
		p = get_perspective_matrix(1200, 800, 45);
		get_mat_as_tab(get_mvp_matrix(m, v, p), trans);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transform"), 1, GL_FALSE, trans);
		glUniform4f(glGetUniformLocation(shaderProgram, "mixvalues"),
					mix.x, mix.y, mix.z, mix.w);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, obj->triangles * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);		
		glfwSwapBuffers(window);
        glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
 	ft_memdel((void **)&(obj->data));
	ft_memdel((void **)&(obj->indices));
	ft_memdel((void **)&obj);
    glfwTerminate();
    return(0);
}
