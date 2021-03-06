/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:22:24 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 14:27:45 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec	update_mix_values(t_vec mix, int mode)
{
	mix.x -= 0.01;
	mix.y -= 0.01;
	mix.z -= 0.01;
	mix.w -= 0.01;
	if (mix.x < 0.0)
		mix.x = 0.0;
	if (mix.y < 0.0)
		mix.y = 0.0;
	if (mix.z < 0.0)
		mix.z = 0.0;
	if (mix.w < 0.0)
		mix.w = 0.0;
	if (mode == 0 && mix.w < 1.0)
		mix.w += 0.02;
	else if (mode == 1 && mix.x < 1.0)
		mix.x += 0.02;
	else if (mode == 2 && mix.y < 1.0)
		mix.y += 0.02;
	else if (mode == 3 && mix.z < 1.0)
		mix.z += 0.02;
	return (mix);
}

void	do_the_gl_stuff(GLFWwindow *window, unsigned int vao, t_obj *obj)
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, obj->triangles * 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glfwSwapBuffers(window);
	glfwPollEvents();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	do_the_mat_stuff(t_vec cam_pos, unsigned int shader_program, t_vec mix)
{
	t_mat	m;
	t_mat	v;
	t_mat	p;
	float	trans[16];

	m = get_model_matrix(identity(), rotate(set_vec(0.0, 1.0, 0.0, 0.0),
											(float)glfwGetTime()), identity());
	v = get_view_matrix(translate(cam_pos), set_vec(0.0, 1.0, 0.0, 0.0),
						0.0, identity());
	p = get_perspective_matrix(W_WIDTH, W_HEIGHT, 45);
	get_mat_as_tab(get_mvp_matrix(m, v, p), trans);
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "transform"),
						1, GL_FALSE, trans);
	glUniform4f(glGetUniformLocation(shader_program, "mixvalues"),
				mix.x, mix.y, mix.z, mix.w);
}

void	ft_loop(GLFWwindow *window, unsigned int vao,
				t_obj *obj, unsigned int shader_program)
{
	t_vec	cam_pos;
	int		tex_mode;
	t_vec	mix;

	cam_pos = set_vec(0.0, 0.0, 1.0, 1.0);
	mix = set_vec(1.0, 0.0, 0.0, 0.0);
	tex_mode = 1;
	while (!glfwWindowShouldClose(window))
	{
		tex_mode = change_tex(tex_mode, window);
		mix = update_mix_values(mix, tex_mode);
		cam_pos = move_view(cam_pos, window);
		do_the_mat_stuff(cam_pos, shader_program, mix);
		do_the_gl_stuff(window, vao, obj);
	}
}
